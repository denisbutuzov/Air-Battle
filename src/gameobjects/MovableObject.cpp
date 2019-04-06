#include <QGraphicsScene>
#include <QTimer>

#include "MovableObject.h"

MovableObject::MovableObject(const std::shared_ptr<QGraphicsScene> &scene,
                             std::unique_ptr<MoveStrategy> &&moveStrategy)
    : GameObject(scene)
    , moveStrategy_(std::move(moveStrategy))
{
}

MovableObject::~MovableObject() = default;

void MovableObject::init()
{
    //call basic method init()
    GameObject::init();

    //connect
    moveTimer_ = std::make_unique<QTimer>();
    connect(moveTimer_.get(), SIGNAL(timeout()),
            this, SLOT(move()));
    moveTimer_->start(50);
}

void MovableObject::setSpeed(unsigned int speed)
{
    speed_ = speed;
}

unsigned int MovableObject::speed() const
{
    return speed_;
}

void MovableObject::move()
{
    moveStrategy_->move(*this);
}
