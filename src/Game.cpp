#include <QKeyEvent>
#include <QDesktopWidget>
#include <QApplication>

#include "GameObjects/PlayerObject.h"
#include "GameObjects/Enemies/EnemyDecorators/ShieldDecorator.h"
#include "GameObjects/Gunshells/Gunshell.h"
#include "GameObjects/Weapons/Weapon.h"
#include "GameObjects/Bonuses/Bonus.h"
#include "HandWeapons/HandWeapon.h"
#include "HandBonuses/HandBonus.h"
#include "SpecialObjects/Subjects/Level.h"
#include "SpecialObjects/Subjects/Score.h"
#include "SpecialObjects/Subjects/Health.h"
#include "SpecialObjects/Subjects/Equipment.h"
#include "SpecialObjects/Observers/HealthObserver.h"
#include "SpecialObjects/Observers/LabelObserver.h"
#include "SpecialObjects/Observers/EquipmentObserver.h"
#include "Visitors/MoveVisitor.h"
#include "FactoryManager.h"
#include "additionals.h"
#include "AppSettings.h"

#include "Game.h"

Game::Game()
{
    const auto &sceneSettings = AppSettings::instance().scene();
    const auto &timeSettings = AppSettings::instance().time();
    const auto &objectsSettings = AppSettings::instance().objects();

    scene_ = std::make_shared<QGraphicsScene>();
    scene_->setSceneRect(0, 0, sceneSettings.width_, sceneSettings.height_);
    setScene(scene_.get());
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(sceneSettings.width_, sceneSettings.height_);
    setBackgroundBrush(QBrush(QImage(sceneSettings.backGround_)));

    player_ = std::make_unique<PlayerObject>(scene_);
    player_->setPixmap(QPixmap(objectsSettings.player_));
    player_->setFlag(QGraphicsItem::ItemIsFocusable);
    player_->setFocus();
    player_->setPos((scene_->width() - player_->pixmap().width())/2,
                    scene_->height() - player_->pixmap().height());
    auto equipment = std::make_shared<Equipment>(scene_);
    equipmentObserver_ = std::make_unique<EquipmentObserver>(equipment);
    equipmentObserver_->show(scene_, QPointF(0.0, 30.0));
    player_->setEquipment(equipment);
    player_->init();

    level_ = std::make_shared<Level>();
    levelObserver_ = std::make_unique<LabelObserver<Level>>(level_, "Level: ");
    levelObserver_->show(scene_, QPointF(250.0, 0.0));

    score_ = std::make_shared<Score>();
    scoreObserver_ = std::make_unique<LabelObserver<Score>>(score_, "Score: ");
    scoreObserver_->show(scene_);

    health_ = std::make_shared<Health>();
    healthObserver_ = std::make_unique<HealthObserver>(health_, objectsSettings.heart_);
    healthObserver_->show(scene_, QPointF(470.0, 10.0));

    connect(&levelChangeTimer_, SIGNAL(timeout()),
            this, SLOT(levelChange()));
    levelChangeTimer_.start(timeSettings.levelChangePeriod_);

    connect(&spawnObjectTimer_, SIGNAL(timeout()),
            this, SLOT(getSpawnObjectFromFactory()));
    spawnObjectTimer_.start(timeSettings.spawnObjectPeriod_);

    connect(&removeObjectTimer_, SIGNAL(timeout()),
            this, SLOT(removeObjectsFromScene()));
    removeObjectTimer_.start(timeSettings.removeObjectPeriod_);

    connect(&moveTimer_, SIGNAL(timeout()),
            this, SLOT(moveGameObjects()));
    moveTimer_.start(timeSettings.moveObjectPeriod_);

    connect(&checkCollisionTimer_, SIGNAL(timeout()),
            this, SLOT(checkCollisionBetweenGameObjects()));
    checkCollisionTimer_.start(timeSettings.checkCollisionPeriod_);

    connect(player_.get(), SIGNAL(shot_sig()),
            this, SLOT(getGunshellFromPlayer()));

    QRect rect = geometry();
    rect.moveCenter(QApplication::desktop()->availableGeometry().center());
    setGeometry(rect);
}

void Game::start()
{
    show();
    levelChangeTimer_.start();
    spawnObjectTimer_.start();
    removeObjectTimer_.start();
    moveTimer_.start();
    checkCollisionTimer_.start();
}

void Game::pause()
{
    hide();
    emit pause_sig();
    levelChangeTimer_.stop();
    spawnObjectTimer_.stop();
    removeObjectTimer_.stop();
    moveTimer_.stop();
    checkCollisionTimer_.stop();
}

void Game::moveGameObjects()
{
    MoveVisitor visitor;
    objectsStorage_.accept(visitor);
}

void Game::getSpawnObjectFromFactory()
{
    auto spawnObject = FactoryManager::createSpawnObject(scene_, level_);
    spawnObject->init();
    objectsStorage_.pushMovableObject(std::move(spawnObject));
}

void Game::getGunshellFromPlayer()
{
    auto gunshell = player_->shoot();
    if(gunshell)
    {
        gunshell->init();
        objectsStorage_.pushGunshell(std::move(gunshell));
    }
}

void Game::removeObjectsFromScene()
{
    objectsStorage_.weapons().remove_if([&](auto &obj){ return obj->y() > scene_->height(); });
    objectsStorage_.bonuses().remove_if([&](auto &obj){ return obj->y() > scene_->height(); });
    objectsStorage_.gunshells().remove_if([](auto &obj){ return obj->y() < 0; });
    objectsStorage_.enemies().remove_if
            (
                [&](auto &obj)
                {
                    if(obj->y() > scene_->height())
                    {
                        health_->decrease();
                        return true;
                    }
                    return false;
                }
            );

    if(health_->value() == 0)
    {
        emit end_sig();
    }
}

void Game::checkCollisionBetweenGameObjects()
{
    objectsStorage_.gunshells().remove_if
            (
                [](auto &gunshell)
                {
                    auto collidingList = gunshell->collidingItems();
                    for(auto *otherObj : collidingList)
                    {
                        if(auto *enemy = dynamic_cast<Enemy *>(otherObj))
                        {
                            enemy->setHitpoint(enemy->hitpoint() - gunshell->damage());
                            return true;
                        }
                    };
                    return false;
                }
            );

    objectsStorage_.enemies().remove_if
            (
                [&](auto &enemy)
                {
                    if (enemy->hitpoint() <= 0)
                    {
                        if(auto *shield = dynamic_cast<ShieldDecorator *>(enemy.get()))
                        {
                            std::unique_ptr<Enemy> enemy(shield->enemy().release());
                            objectsStorage_.pushEnemy(std::move(enemy));
                        }
                        else
                        {
                            score_->increase();
                        }
                        return true;
                    }
                    return false;
                }
            );

    objectsStorage_.weapons().remove_if
            (
                [](auto &weapon)
                {
                    auto collidingList = weapon->collidingItems();
                    for(auto *otherObj : collidingList)
                    {
                        if(auto *player = dynamic_cast<PlayerObject *>(otherObj))
                        {
                            player->takeWeapon(weapon->handWeapon());
                            return true;
                        }
                    };
                    return false;
                }
            );

    objectsStorage_.bonuses().remove_if
            (
                [&](auto &bonus)
                {
                    auto collidingList = bonus->collidingItems();
                    for(auto *otherObj : collidingList)
                    {
                        if(auto *player = dynamic_cast<PlayerObject *>(otherObj))
                        {
                            player->takeBonus(bonus->handBonus(player, &objectsStorage_));
                            return true;
                        }
                    };
                    return false;
                }
            );
}

void Game::levelChange()
{
    level_->increase();
}

void Game::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Escape)
    {
        hide();
        pause();
    }
    else
    {
        player_->keyPressEvent(event);
    }
}

void Game::keyReleaseEvent(QKeyEvent *event)
{
    player_->keyReleaseEvent(event);
}

void Game::closeEvent(QCloseEvent *event)
{
    emit close_sig();
}

Game::~Game() = default;
