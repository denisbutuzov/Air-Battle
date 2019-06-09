#include <QGraphicsScene>

#include "MoveStrategies/MoveStrategy.h"

#include "MovableObject.h"

MovableObject::MovableObject(std::weak_ptr<QGraphicsScene> scene,
                             std::shared_ptr<MoveStrategy> moveStrategy)
    : GameObject(scene)
    , moveStrategy_(moveStrategy)
{
}

void MovableObject::move()
{
    moveStrategy_->move(*this);
}

void MovableObject::setSpeed(unsigned int speed)
{
    moveStrategy_->setSpeed(speed);
}

unsigned int MovableObject::speed() const
{
    return moveStrategy_->speed();
}

std::shared_ptr<MoveStrategy> MovableObject::moveStrategy() const
{
    return moveStrategy_;
}
