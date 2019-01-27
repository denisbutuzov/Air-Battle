#include <QMediaPlaylist>
#include <QTimer>

#include "PlayerObject.h"
#include "SpawnObject.h"
#include "Level1Factory.h"

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

    //spawn enemies
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), SLOT(spawn()));
    timer->start(2000);
}

void Game::spawn()
{
    auto *factory = new Level1Factory(scene_);
    auto *spawnObject = callFactory(factory);
    spawnObject->init();
}

SpawnObject *Game::callFactory(AbstractLevelFactory *factory)
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
