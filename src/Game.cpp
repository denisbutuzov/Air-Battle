#include <QMediaPlaylist>
#include <QTimer>

#include "PlayerObject.h"
#include "SpawnObject.h"
#include "Machinegun.h"
#include "Bazooka.h"
#include "Enemy.h"

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
    setBackgroundBrush(QBrush(QImage(":/images/images/Space.jpg")));

    //spawn enemies
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), SLOT(spawn()));
    timer->start(2000);
}

void Game::spawn()
{
    static int n = 0;
    SpawnObject *spawnObject = nullptr;

    if(n++ == 6)
    {
        int random_number = rand() % 10;
        if(random_number > 5)
        {
            spawnObject = new Bazooka();
        }
        else
        {
            spawnObject = new Machinegun();
        }
        n = 0;
    }
    else
    {
        spawnObject = new Enemy();
    }

    spawnObject->init(scene());
}
