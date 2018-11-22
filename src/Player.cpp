#include <QKeyEvent>
#include <QGraphicsScene>

#include "Bullet.h"
#include "Rocket.h"
#include "Enemy.h"

#include "Player.h"

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
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
        bullet->setPos(x() + sideCounter * (pixmap().width() - bullet->pixmap().width()), y() + 70);
        scene()->addItem(bullet);

        sideCounter++;
        if(sideCounter > 1)
        {
            sideCounter = 0;
        }
    }
    //press V key - create a rocket
    else if(event->key() == Qt::Key_V)
    {
        Rocket *rocket = new Rocket();
        rocket->setPos(x() + (pixmap().width() - rocket->pixmap().width())/2, y() - 20);
        scene()->addItem(rocket);
    }
}

void Player::spawn()
{
    //create an enemy
    Enemy *enemy = new Enemy();
    scene()->addItem(enemy);
}
