#include <QGraphicsScene>
#include <QKeyEvent>

#include "HandWeapons/HandWeapon.h"
#include "GameObjects/Gunshells/Gunshell.h"
#include "SpecialObjects/Subjects/Magazine.h"

#include "PlayerObject.h"

PlayerObject::PlayerObject(std::shared_ptr<QGraphicsScene> scene,
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

void PlayerObject::changeWeapon()
{
    weapons_->changeWeapon();
}

void PlayerObject::setMagazine(std::unique_ptr<Magazine> &&magazine)
{
    weapons_ = std::move(magazine);
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
    //press up key - move up
    else if(event->key() == Qt::Key_Up)
    {
        stepUp();
    }
    //press down key - move down
    else if(event->key() == Qt::Key_Down)
    {
        stepDown();
    }
    //press shift key - change a weapon
    else if(event->key() == Qt::Key_Shift)
    {
        changeWeapon();
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

void PlayerObject::stepUp()
{
    if(y() > SCENE_PART_TO_NOT_MOVE * scene()->height())
    {
        setPos(x(), y() - 10);
    }
}

void PlayerObject::stepDown()
{
    if(y() < scene()->height() - pixmap().height())
    {
        setPos(x(), y() + 10);
    }
}
