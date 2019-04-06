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
            this, SLOT(spawn()));
    spawnObjectTimer_->start(2000);

    connect(player_.get(), SIGNAL(shoot_sig()),
            this, SLOT(getGunshellFromPlayer()));
}

Game::~Game() = default;

void Game::spawn()
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

std::unique_ptr<MovableObject> Game::createSpawnObject(AbstractLevelFactory &factory)
{
    return factory.enemy();
}
