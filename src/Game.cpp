#include <QMediaPlaylist>
#include <QTimer>

#include <memory>

#include "Level1Factory.h"
#include "Level2Factory.h"
#include "Level3Factory.h"
#include "Score.h"
#include "Health.h"

#include "Game.h"

Game::Game(QWidget *parent)
{
    //create a scene
    scene_ = new QGraphicsScene();
    scene_->setSceneRect(0, 0, 600, 800);

    //add a view
    setScene(scene_);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(600, 800);

    //create an item to put unto the scene
    player_ = new PlayerObject(scene_);
    player_->init();

    score_ = Score::instance();
    score_->show(scene_);

    health_ = Health::instance();
    health_->show(scene_, QPointF(scene_->width() - 155.0, 10.0));

    level_ = new Level();
    level_->show(scene_, QPointF(scene_->width()/2 - 65.0, 0.0));

    //make rect focusable
    player_->setFlag(QGraphicsItem::ItemIsFocusable);
    player_->setFocus();

    //play background sound
    QMediaPlaylist *playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/sounds/sounds/plane.wav"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);
    QMediaPlayer *backsound = new QMediaPlayer();
    backsound->setPlaylist(playlist);
    backsound->play();

    //set background image
    setBackgroundBrush(QBrush(QImage(":/images/images/Space.jpg")));

    //spawn game objects
    auto *spawnObjectTimer = new QTimer();
    connect(spawnObjectTimer, SIGNAL(timeout()), SLOT(spawn()));
    spawnObjectTimer->start(2000);

    //level change
    auto *levelChangeTimer = new QTimer();
    connect(levelChangeTimer, SIGNAL(timeout()), level_, SLOT(change()));
    levelChangeTimer->start(10000);
}

void Game::spawn()
{
    std::unique_ptr<AbstractLevelFactory> factory;
    switch(level_->level())
    {
    case 1:
        factory = std::make_unique<Level1Factory>(scene_);
        break;
    case 2:
        factory = std::make_unique<Level2Factory>(scene_);
        break;
    case 3:
        factory = std::make_unique<Level3Factory>(scene_);
        break;
    default:
        break;
    }

    auto *spawnObject = createSpawnObject(factory.get());
    spawnObject->init();
}

SpawnObject *Game::createSpawnObject(AbstractLevelFactory *factory)
{
    unsigned int n = rand() % 7;
    if(n > 4)
    {
        return factory->weapon();
    }
    else
    {
        return factory->enemy();
    }
}

