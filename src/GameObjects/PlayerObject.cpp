#include <QGraphicsScene>
#include <QKeyEvent>

#include <unordered_map>

#include "HandWeapons/HandWeapon.h"
#include "GameObjects/Gunshells/Gunshell.h"
#include "SpecialObjects/Subjects/Equipment.h"

#include "PlayerObject.h"

constexpr double INACTION_SCENE_PART = 0.66;

PlayerObject::PlayerObject(std::weak_ptr<QGraphicsScene> scene)
    : GameObject(scene)
    , timerAtWork_(false)
{
    equipment_ = std::make_unique<Equipment>(scene);
}

PlayerObject::~PlayerObject() = default;

void PlayerObject::setEquipment(std::shared_ptr<Equipment> equipment)
{
    equipment_ = equipment;
}

std::unique_ptr<Gunshell> PlayerObject::shoot() const
{
    return equipment_->shoot(x() + pixmap().width()/2, y());
}

std::shared_ptr<Equipment> PlayerObject::equipment() const
{
    return equipment_;
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
    static const std::unordered_map<Qt::Key, std::function<void(void)>> FUNCTION_MAP
    {
        { Qt::Key_Left, [&]() -> void { stepLeft(); } },
        { Qt::Key_Right, [&]() -> void { stepRight(); } },
        { Qt::Key_Up, [&]() -> void { stepUp(); } },
        { Qt::Key_Down, [&]() -> void { stepDown(); } },
        { Qt::Key_Shift, [&]() -> void { equipment()->changeWeapon(); } },
        { Qt::Key_R, [&]() -> void { equipment()->reloadWeapon(); } },
        { Qt::Key_Space, [&]() -> void { emit shot_sig(); } }
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
            function();
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
