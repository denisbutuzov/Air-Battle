#include "SpawnObject.h"

SpawnObject::SpawnObject(QGraphicsItem *parent)
    : MovableObject(parent)
{

}

void SpawnObject::move()
{
    //move object down
    setPos(x(), y() + speed());

    //delete object when it is behind the scene
    if(y() > scene()->height())
    {
        //remove from the scene
        scene()->removeItem(this);
        delete this;
    }
}

void SpawnObject::setSpeed()
{
    speed() = 5;
}

void SpawnObject::setStartObjectPos()
{
    int random_number = rand() % static_cast<int>(scene()->width() - pixmap().width());
    setPos(random_number, 0 - pixmap().height());
}
