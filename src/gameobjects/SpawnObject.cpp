#include "SpawnObject.h"

SpawnObject::SpawnObject(QGraphicsScene *scene)
    : MovableObject(scene)
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
    int randomNumber = rand() % static_cast<int>(scene()->width() - pixmap().width());
    setPos(randomNumber, 0 - pixmap().height());
}
