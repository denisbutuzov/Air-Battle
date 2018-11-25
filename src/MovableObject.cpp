#include <QTimer>

#include "MovableObject.h"

MovableObject::MovableObject(QGraphicsItem *parent)
    : GameObject(parent)
{

}

void MovableObject::show(QGraphicsScene *scene)
{
    //call basic method show
    GameObject::show(scene);

    //set speed of object
    setSpeed();

    //connect
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

unsigned int &MovableObject::speed()
{
    return speed_;
}
