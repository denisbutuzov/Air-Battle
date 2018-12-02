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

void MovableObject::destroyObject(GameObject *object)
{
    scene()->removeItem(object);
    delete object;
}

unsigned int &MovableObject::speed()
{
    return speed_;
}

void MovableObject::setSpeed()
{
    speed_ = 5;
}
