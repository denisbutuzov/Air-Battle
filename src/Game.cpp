#include <QTimer>

#include <memory>

#include "PresetPositionBuilder.h"
#include "Level1Factory.h"
#include "Level2Factory.h"
#include "PlayerObject.h"
#include "Enemy.h"
#include "Weapon.h"
#include "HandWeapon.h"
#include "Gunshell.h"
#include "MoveVisitor.h"

#include "Game.h"

Game::Game(QWidget *parent)
    : level_(1)
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
    PresetPositionBuilder gameObjectBuilder;
    player_ = gameObjectBuilder.buildPlayer(scene_, ":/images/images/Player.png");
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
    std::unique_ptr<AbstractLevelFactory> levelFactory;

    if(level_ == 1)
    {
        levelFactory = std::make_unique<Level1Factory>(scene_);
    }
    else
    {
        levelFactory = std::make_unique<Level2Factory>(scene_);
    }

    auto spawnObject = createSpawnObject(levelFactory);
    spawnObject->init();

    if (dynamic_cast<Enemy *>(spawnObject.get()))
    {
        enemies_.push_back(std::move(spawnObject));
    }
    else if (dynamic_cast<Weapon *>(spawnObject.get()))
    {
        weapons_.push_back(std::move(spawnObject));
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
    enemies_.remove_if([scene=scene_](auto &obj){return obj->y() > scene->height();});
    weapons_.remove_if([scene=scene_](auto &obj){return obj->y() > scene->height();});
}

void Game::checkCollisionBetweenGameObjects()
{
    gunshells_.remove_if
            (
                [](auto &obj)
                {
                    auto collidingList = obj->collidingItems();
                    for(auto *otherObj : collidingList)
                    {
                        if(auto *enemy = dynamic_cast<Enemy *>(otherObj))
                        {
                            auto *gunshell = dynamic_cast<Gunshell *>(obj.get());
                            enemy->setHitpoint(enemy->hitpoint() - gunshell->damage());
                            return true;
                        }
                    };
                    return false;
                }
            );

    enemies_.remove_if
            (
                [](auto &obj)
                {
                    auto *enemy = dynamic_cast<Enemy *>(obj.get());
                    return enemy->hitpoint() == 0;
                }
            );

    weapons_.remove_if
            (
                [](auto &obj)
                {
                    auto collidingList = obj->collidingItems();
                    for(auto *otherObj : collidingList)
                    {
                        if(auto *player = dynamic_cast<PlayerObject *>(otherObj))
                        {
                            auto *weapon = dynamic_cast<Weapon *>(obj.get());
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
    if(level_ < 2)
    {
        ++level_;
    }
}

std::unique_ptr<MovableObject> Game::createSpawnObject(std::unique_ptr<AbstractLevelFactory> &factory)
{
    int randomNumber = rand() % 10;
    if(randomNumber > 6)
    {
        return factory->weapon();
    }
    else
    {
        return factory->enemy();
    }
}
