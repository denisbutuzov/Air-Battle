#include <QGraphicsScene>

#include "MovableObject.h"

MovableObject::MovableObject(const std::shared_ptr<QGraphicsScene> &scene,
                             std::unique_ptr<MoveStrategy> &&moveStrategy)
    : GameObject(scene)
    , moveStrategy_(std::move(moveStrategy))
{
}

MovableObject::~MovableObject() = default;

void MovableObject::move()
{
    moveStrategy_->move(*this);
}

void MovableObject::setSpeed(unsigned int speed)
{
    speed_ = speed;
}

unsigned int MovableObject::speed() const
{
    return speed_;
}
