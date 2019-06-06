#include <QGraphicsScene>
#include <QKeyEvent>

#include <unordered_map>

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

void PlayerObject::reloadWeapon()
{
    weapons_->reloadWeapon();
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
    static const std::unordered_map<int, void(PlayerObject::*)(void)> FUNCTION_MAP
    {
        { Qt::Key_Left, &PlayerObject::stepLeft },
        { Qt::Key_Right, &PlayerObject::stepRight },
        { Qt::Key_Up, &PlayerObject::stepUp },
        { Qt::Key_Down, &PlayerObject::stepDown },
        { Qt::Key_Shift, &PlayerObject::changeWeapon },
        { Qt::Key_R, &PlayerObject::reloadWeapon },
        { Qt::Key_Space, &PlayerObject::shoot_sig }
    };

    pressedKeys_.insert(event->key());
    for(auto key : pressedKeys_)
    {
        auto it = FUNCTION_MAP.find(key);
        if(it != FUNCTION_MAP.end())
        {
            auto function = it->second;
            (this->*function)();
        }
    }
}

void PlayerObject::keyReleaseEvent(QKeyEvent *event)
{
    if(!event->isAutoRepeat())
    {
        pressedKeys_.erase(event->key());
    }
}

void PlayerObject::stepLeft()
{
    if(x() > 0)
    {
        setPos(x() - 10, y());
    }
}

void PlayerObject::stepRight()
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
