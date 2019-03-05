#include <QGraphicsScene>
#include <QKeyEvent>

#include "HandWeapon.h"

#include "PlayerObject.h"

PlayerObject::PlayerObject(const std::shared_ptr<QGraphicsScene> &scene,
                           std::unique_ptr<HandWeapon> &&weapon)
    : GameObject(scene)
    , weapon_(std::move(weapon))
{
}

PlayerObject::~PlayerObject() = default;

void PlayerObject::takeWeapon(std::unique_ptr<HandWeapon> &&weapon)
{
    weapon_ = std::move(weapon);
}

void PlayerObject::keyPressEvent(QKeyEvent *event)
{
    //press left key - move to left
    if(event->key() == Qt::Key_Left)
    {
        stepToLeft();
    }
    //press right key - move to right
    else if(event->key() == Qt::Key_Right)
    {
        stepToRight();
    }
    //press space key - create a bullet
    else if(event->key() == Qt::Key_Space)
    {
        shoot();
    }
}

void PlayerObject::shoot() const
{
    weapon_->shoot(x() + pixmap().width()/2, y());
}

void PlayerObject::stepToLeft()
{
    if(x() > 0)
    {
        setPos(x() - 10, y());
    }
}

void PlayerObject::stepToRight()
{
    if(x() + pixmap().width() < scene()->width())
    {
        setPos(x() + 10, y());
    }
}
