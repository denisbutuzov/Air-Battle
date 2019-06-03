#include <QGraphicsScene>

#include "MoveStrategies/MoveStrategy.h"

#include "MovableObject.h"

MovableObject::MovableObject(std::shared_ptr<QGraphicsScene> scene,
                             const QString &pixmap,
                             std::shared_ptr<MoveStrategy> moveStrategy)
    : GameObject(scene, pixmap)
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
