#include <QKeyEvent>

#include "Bullet.h"
#include "Rocket.h"
#include "Enemy.h"

#include "PlayerObject.h"

PlayerObject::PlayerObject(QGraphicsItem *parent)
    : GameObject(parent)
{
}

void PlayerObject::keyPressEvent(QKeyEvent *event)
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
        bullet->init(scene());

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
        rocket->init(scene());
    }
}

void PlayerObject::setObjectImage()
{
    setPixmap(QPixmap(":/images/images/player_plane.png"));
}

void PlayerObject::setStartObjectPos()
{
    setPos(scene()->width()/2 - pixmap().width()/2, scene()->height() - pixmap().height());
}
