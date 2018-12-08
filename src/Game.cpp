#include <QMediaPlaylist>
#include <QTimer>

#include "PlayerObject.h"
#include "Enemy.h"

#include "Game.h"

Game::Game(QWidget *parent)
{
    //create a scene
    scene_ = new QGraphicsScene();
    scene_->setSceneRect(0, 0, 800, 600);

    //add a view
    setScene(scene_);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800, 600);

    //create an item to put unto the scene
    player_ = new PlayerObject();
    player_->init(scene_);
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
    setBackgroundBrush(QBrush(QImage(":/images/images/background.jpeg")));

    //spawn enemies
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), SLOT(spawn()));
    timer->start(2000);
}

void Game::spawn()
{
    Enemy *enemy = new Enemy();
    enemy->init(scene());
}
