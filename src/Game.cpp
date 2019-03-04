#include <QTimer>

#include <memory>

#include "Level1Factory.h"
#include "Level2Factory.h"
#include "PlayerObject.h"
#include "HandWeapon.h"
#include "Enemy.h"

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
    player_ = std::make_unique<PlayerObject>(scene_, std::make_unique<HandWeapon>(scene_));
    player_->setPixmap(QPixmap(":/images/images/Player.png"));
    player_->setPos((scene_->width() - player_->pixmap().width())/2,
                    scene_->height() - player_->pixmap().height());
    player_->setFlag(QGraphicsItem::ItemIsFocusable);
    player_->setFocus();
    player_->init();

    //set background image
    setBackgroundBrush(QBrush(QImage(":/images/images/Space.jpg")));

    spawnObjectTimer_ = std::make_unique<QTimer>();
    connect(spawnObjectTimer_.get(), SIGNAL(timeout()),
            this, SLOT(spawn()));
    spawnObjectTimer_->start(2000);
}

Game::~Game() = default;

void Game::spawn()
{
    std::unique_ptr<AbstractLevelFactory> levelFactory;
    levelFactory = std::make_unique<Level1Factory>(scene_);

    auto *spawnObject = createSpawnObject(levelFactory);
    spawnObject->init();
}

MovableObject *Game::createSpawnObject(std::unique_ptr<AbstractLevelFactory> &factory)
{
    return factory->enemy();
}
