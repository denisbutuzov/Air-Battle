#include <QTimer>

#include "MovableObject.h"

MovableObject::MovableObject(QGraphicsItem *parent)
    : GameObject(parent)
{
}

void MovableObject::init(QGraphicsScene *scene)
{
    //call basic method show
    GameObject::init(scene);

    //set speed of object
    setSpeed();

    //connect
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
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

