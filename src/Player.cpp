#include <QKeyEvent>
#include <QGraphicsScene>

#include "Bullet.h"
#include "Enemy.h"

#include "Player.h"

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    bulletsound_ = new QMediaPlayer();
    bulletsound_->setMedia(QUrl("qrc:/sounds/sounds/bullet.wav"));
}

void Player::keyPressEvent(QKeyEvent *event)
{
    //variable for alternation shots
    static int sideCounter = 0;

    //press left key - move to left
    if(event->key() == Qt::Key_Left)
    {
        if(x() > 0)
        {
            setPos(x() - 10, y());
        }
    }
    //press right key - move to right
    else if(event->key() == Qt::Key_Right)
    {
        if(x() + pixmap().width() < scene()->width())
        {
            setPos(x() + 10, y());
        }
    }
    //press space key - create a bullet
    else if(event->key() == Qt::Key_Space)
    {
        Bullet *bullet = new Bullet();
        bullet->setPos(x() + sideCounter * (pixmap().width() - bullet->pixmap().width()), y());
        scene()->addItem(bullet);

        sideCounter++;
        if(sideCounter > 1)
        {
            sideCounter = 0;
        }

        //play bullet sound
        if(bulletsound_->state() == QMediaPlayer::PlayingState)
        {
            bulletsound_->setPosition(0);
        }
        else if(bulletsound_->state() == QMediaPlayer::StoppedState)
        {
            bulletsound_->play();
        }
    }
}

void Player::spawn()
{
    //create an enemy
    Enemy *enemy = new Enemy();
    scene()->addItem(enemy);
}
