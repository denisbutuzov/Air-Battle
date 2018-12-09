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
        //remove from the scene and memory
        destroy();
    }
}

void SpawnObject::setStartObjectPos()
{
    int random_number = rand() % static_cast<int>(scene()->width() - pixmap().width());
    setPos(random_number, 0 - pixmap().height());
}
