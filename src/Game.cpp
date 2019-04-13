#include <QTimer>

#include <memory>

#include "PresetPositionBuilder.h"
#include "Level1Factory.h"
#include "PlayerObject.h"
#include "Enemy.h"
#include "Gunshell.h"

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
}

void Game::moveGameObjects()
{

}

Game::~Game() = default;

void Game::getSpawnObjectFromFactory()
{
    Level1Factory levelFactory(scene_);

    auto spawnObject = createSpawnObject(levelFactory);
    spawnObject->init();

    if (dynamic_cast<Enemy *>(spawnObject.get()))
    {
        enemies_.push_back(std::move(spawnObject));
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
}

std::unique_ptr<MovableObject> Game::createSpawnObject(AbstractLevelFactory &factory)
{
    return factory.enemy();
}
