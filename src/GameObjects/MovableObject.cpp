#include <QGraphicsScene>

#include "MovableObject.h"

MovableObject::MovableObject(const std::shared_ptr<QGraphicsScene> &scene,
                             const QString &pixmap,
                             const std::shared_ptr<MoveStrategy> &moveStrategy)
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
    speed_ = speed;
}

unsigned int MovableObject::speed() const
{
    return speed_;
}

std::shared_ptr<MoveStrategy> &MovableObject::moveStrategy()
{
    return moveStrategy_;
}
