#include <QGraphicsScene>
#include <QKeyEvent>

#include <unordered_map>

#include "HandWeapons/HandGun.h"
#include "GameObjects/Gunshells/Gunshell.h"

#include "PlayerObject.h"

constexpr double INACTION_SCENE_PART = 0.66;

PlayerObject::PlayerObject(std::weak_ptr<QGraphicsScene> scene)
    : GameObject(scene)
    , timerAtWork_(false)
{
    weapon_ = std::make_unique<HandGun>(scene);
}

PlayerObject::~PlayerObject() = default;

void PlayerObject::takeWeapon(std::unique_ptr<HandWeapon> &&weapon)
{
    weapon_ = std::move(weapon);
}

std::unique_ptr<Gunshell> PlayerObject::shoot() const
{
    return weapon_->shoot(x() + pixmap().width()/2, y());
}

void PlayerObject::keyPressEvent(QKeyEvent *event)
{
    if(!event->isAutoRepeat())
    {
        pressedKeys_.insert(static_cast<Qt::Key>(event->key()));
        if(!timerAtWork_)
        {
            startTimer(std::chrono::milliseconds(33));
            timerAtWork_ = true;
        }
    }
}

void PlayerObject::keyReleaseEvent(QKeyEvent *event)
{
    if(!event->isAutoRepeat())
    {
        pressedKeys_.erase(static_cast<Qt::Key>(event->key()));
    }
}

void PlayerObject::timerEvent(QTimerEvent *event)
{
    static const std::unordered_map<Qt::Key, void(PlayerObject::*)(void)> FUNCTION_MAP
    {
        { Qt::Key_Left, &PlayerObject::stepLeft },
        { Qt::Key_Right, &PlayerObject::stepRight },
        { Qt::Key_Up, &PlayerObject::stepUp },
        { Qt::Key_Down, &PlayerObject::stepDown },
        { Qt::Key_Space, &PlayerObject::shot_sig },
        { Qt::Key_R, &PlayerObject::reloadWeapon }
    };

    if(pressedKeys_.empty())
    {
        killTimer(event->timerId());
        timerAtWork_ = false;
        return;
    }

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

void PlayerObject::stepLeft()
{
    if(x() > 0)
    {
        setPos(x() - 10, y());
    }
}

void PlayerObject::stepRight()
{
    if(scene().expired())
    {
        return;
    }
    if(x() + pixmap().width() < scene().lock()->width())
    {
        setPos(x() + 10, y());
    }
}

void PlayerObject::stepUp()
{
    if(scene().expired())
    {
        return;
    }
    if(y() > INACTION_SCENE_PART * scene().lock()->height())
    {
        setPos(x(), y() - 10);
    }
}

void PlayerObject::stepDown()
{
    if(scene().expired())
    {
        return;
    }
    if(y() < scene().lock()->height() - pixmap().height())
    {
        setPos(x(), y() + 10);
    }
}

void PlayerObject::reloadWeapon()
{
    weapon_->reload();
}
