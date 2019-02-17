#include <QGraphicsScene>
#include <QTimer>

#include "MovableObject.h"

MovableObject::MovableObject(QGraphicsScene *scene)
    : GameObject(scene)
{
}

MovableObject::~MovableObject()
{
    delete moveObjectTimer_;
}

void MovableObject::init()
{
    //call basic method show
    GameObject::init();

    //set speed of object
    setSpeed();

    //connect
    moveObjectTimer_ = new QTimer(this);
    connect(moveObjectTimer_, SIGNAL(timeout()), this, SLOT(move()));

    moveObjectTimer_->start(50);
}

unsigned int MovableObject::speed() const
{
    return speed_;
}

void MovableObject::destroy()
{
    destroy(this);
}

void MovableObject::destroy(GameObject *object)
{
    scene()->removeItem(object);
    delete object;
}

void MovableObject::setSpeed(unsigned int speed)
{
    speed_ = speed;
}

void MovableObject::setSpeed()
{
    setSpeed(5);
}

