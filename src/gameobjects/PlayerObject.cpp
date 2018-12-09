#include <QKeyEvent>

#include "HandMachinegun.h"

#include "PlayerObject.h"

PlayerObject::PlayerObject(QGraphicsItem *parent)
    : GameObject(parent)
{
    weapon_ = new HandMachinegun();
}

void PlayerObject::takeWeapon(IHandWeapon *weapon)
{
    delete weapon_;
    weapon_ = weapon;
}

void PlayerObject::keyPressEvent(QKeyEvent *event)
{
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
        shoot();
    }
}

void PlayerObject::shoot()
{
    weapon_->shoot(scene(), x() + pixmap().width()/2, y());
}

void PlayerObject::setObjectImage()
{
    setPixmap(QPixmap(":/images/images/player_plane.png"));
}

void PlayerObject::setStartObjectPos()
{
    setPos(scene()->width()/2 - pixmap().width()/2, scene()->height() - pixmap().height());
}
