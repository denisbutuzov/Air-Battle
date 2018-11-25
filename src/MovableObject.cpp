#include <QTimer>

#include "MovableObject.h"

MovableObject::MovableObject(QGraphicsItem *parent)
    : GameObject(parent)
{

}

void MovableObject::draw(QGraphicsScene *scene)
{
    //call basic method draw
    GameObject::draw(scene);

    //set speed of object
    setSpeed();

    //connect
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}
