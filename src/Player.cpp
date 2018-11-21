#include <QKeyEvent>
#include <QGraphicsScene>

#include "Bullet.h"
#include "Enemy.h"

#include "Player.h"

Player::Player(QGraphicsItem *parent): QGraphicsRectItem(parent)
{
    bulletsound_ = new QMediaPlayer();
    bulletsound_->setMedia(QUrl("qrc:/sounds/sounds/bullet.wav"));
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left)
    {
        if(x() > 0)
            setPos(x() - 10, y());
    }
    else if(event->key() == Qt::Key_Right)
    {
        if(x() + 100 < 800)
            setPos(x() + 10, y());
    }
    //create a bullet
    else if(event->key() == Qt::Key_Space)
    {
        Bullet *bullet = new Bullet();
        bullet->setPos(x(), y());
        scene()->addItem(bullet);

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
