#include <QKeyEvent>
#include <QGraphicsScene>

#include "Bullet.h"
#include "Enemy.h"

#include "Player.h"

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
    }
}

void Player::spawn()
{
    //create an enemy
    Enemy *enemy = new Enemy();
    scene()->addItem(enemy);
}
