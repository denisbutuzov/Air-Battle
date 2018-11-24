#include <QGraphicsScene>
#include <QTimer>

#include "SpawnObject.h"

SpawnObject::SpawnObject(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    //set random position of spawn object
    int random_number = rand() % 700;
    setPos(random_number, 0 - pixmap().height());

    //set speed of object
    setSpeed();

    //start moving
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void SpawnObject::move()
{
    //move object down
    setPos(x(), y() + speed_);

    //delete when object is behind the scene
    if(y() > scene()->height())
    {
        //remove from the scene
        scene()->removeItem(this);
        delete this;
    }
}

void SpawnObject::setSpeed()
{
    speed_ = 5;
}
