#include <QTimer>

#include <memory>

#include "GameObjects/PlayerObject.h"
#include "GameObjects/Enemies/EnemyDecorators/ShieldDecorator.h"
#include "GameObjects/Weapons/Weapon.h"
#include "GameObjects/Gunshells/Gunshell.h"
#include "HandWeapons/HandWeapon.h"
#include "HandWeapons/HandGun.h"
#include "Visitors/MoveVisitor.h"
#include "SpecialObjects/Subjects/Score.h"
#include "SpecialObjects/Subjects/Level.h"
#include "SpecialObjects/Subjects/Health.h"
#include "SpecialObjects/Observers/HealthObserver.h"
#include "Director.h"

#include "Game.h"

Game::Game(QWidget *parent)
{
    //create a scene
    scene_ = std::make_shared<QGraphicsScene>();
    scene_->setSceneRect(0, 0, 600, 800);

    //add a view
    setScene(scene_.get());
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(600, 800);

    //create an item to put unto the scene
    player_ = std::make_unique<PlayerObject>(scene_, ":/images/images/Player.png",
                                             std::make_unique<HandGun>(scene_));
    player_->setFlag(QGraphicsItem::ItemIsFocusable);
    player_->setFocus();
    player_->setPos((scene_->width() - player_->pixmap().width())/2,
                    scene_->height() - player_->pixmap().height());
    player_->init();

    //set background image
    setBackgroundBrush(QBrush(QImage(":/images/images/Space.jpg")));

    spawnObjectTimer_ = std::make_unique<QTimer>();
    connect(spawnObjectTimer_.get(), SIGNAL(timeout()),
            this, SLOT(getSpawnObjectFromFactory()));
    spawnObjectTimer_->start(2000);

    connect(player_.get(), SIGNAL(shoot_sig()),
            this, SLOT(getGunshellFromPlayer()));

    removeObjectTimer_ = std::make_unique<QTimer>();
    connect(removeObjectTimer_.get(), SIGNAL(timeout()),
            this, SLOT(removeObjectsFromScene()));
    removeObjectTimer_->start(50);

    checkCollisionTimer_ = std::make_unique<QTimer>();
    connect(checkCollisionTimer_.get(), SIGNAL(timeout()),
            this, SLOT(checkCollisionBetweenGameObjects()));
    checkCollisionTimer_->start(50);

    moveTimer_ = std::make_unique<QTimer>();
    connect(moveTimer_.get(), SIGNAL(timeout()),
            this, SLOT(moveGameObjects()));
    moveTimer_->start(50);

    levelChangeTimer_ = std::make_unique<QTimer>();
    connect(levelChangeTimer_.get(), SIGNAL(timeout()),
            this, SLOT(levelChange()));
    levelChangeTimer_->start(10000);

    score_ = Score::instance();
    scoreObserver_ = new LabelObserver<Score>(score_, "Score: ");
    scoreObserver_->show(scene_);

    level_ = Level::instance();
    levelObserver_ = new LabelObserver<Level>(level_, "Level: ");
    levelObserver_->show(scene_, QPointF(250.0, 0.0));

    health_ = Health::instance();
    healthObserver_ = new HealthObserver(health_);
    healthObserver_->show(scene_, QPointF(470.0, 10.0));
}

void Game::moveGameObjects()
{
    MoveVisitor visitor;
    for(auto iter = std::begin(enemies_); iter != std::end(enemies_); ++iter)
    {
        (*iter)->accept(visitor);
    }

    for(auto iter = std::begin(gunshells_); iter != std::end(gunshells_); ++iter)
    {
        (*iter)->accept(visitor);
    }

    for(auto iter = std::begin(weapons_); iter != std::end(weapons_); ++iter)
    {
        (*iter)->accept(visitor);
    }
}

Game::~Game() = default;

void Game::getSpawnObjectFromFactory()
{
    auto spawnObject = Director::createSpawnObject(scene_, level_);
    spawnObject->init();

    if (auto *enemy = dynamic_cast<Enemy *>(spawnObject.get()))
    {
        std::unique_ptr<Enemy> upEnemy(enemy);
        spawnObject.release();
        enemies_.push_back(std::move(upEnemy));
    }
    else if (auto *weapon = dynamic_cast<Weapon *>(spawnObject.get()))
    {
        std::unique_ptr<Weapon> upWeapon(weapon);
        spawnObject.release();
        weapons_.push_back(std::move(upWeapon));
    }
}

void Game::getGunshellFromPlayer()
{
    auto gunshell = player_->shoot();
    gunshell->init();
    gunshells_.push_back(std::move(gunshell));
}

void Game::removeObjectsFromScene()
{
    gunshells_.remove_if([](auto &obj){return obj->y() < 0;});
    weapons_.remove_if([scene=scene_](auto &obj){return obj->y() > scene->height();});
    enemies_.remove_if
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
}

void Game::checkCollisionBetweenGameObjects()
{
    gunshells_.remove_if
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

    enemies_.remove_if
            (
                [&](auto &enemy)
                {
                    if (enemy->hitpoint() <= 0)
                    {
                        if(auto *shield = dynamic_cast<ShieldDecorator *>(enemy.get()))
                        {
                            enemies_.push_back(shield->enemy());
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

    weapons_.remove_if
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
}

void Game::levelChange()
{
    level_->increase();
}
