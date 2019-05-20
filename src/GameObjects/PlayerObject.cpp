#include <QGraphicsScene>
#include <QKeyEvent>

#include "HandWeapons/HandWeapon.h"
#include "GameObjects/Gunshells/Gunshell.h"
#include "Magazine.h"

#include "PlayerObject.h"

PlayerObject::PlayerObject(const std::shared_ptr<QGraphicsScene> &scene,
                           const QString &pixmap)
    : GameObject(scene, pixmap)
{
    weapons_ = std::make_unique<Magazine>(scene);
}

PlayerObject::~PlayerObject() = default;

void PlayerObject::takeWeapon(std::unique_ptr<HandWeapon> &&weapon)
{
    weapons_->addWeapon(std::move(weapon));
}

std::unique_ptr<Gunshell> PlayerObject::shoot() const
{
    return weapons_->shoot(x() + pixmap().width()/2, y());
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
        emit shoot_sig();
    }
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
