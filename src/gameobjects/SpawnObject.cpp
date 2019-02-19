#include <QGraphicsScene>

#include "SpawnObject.h"

SpawnObject::SpawnObject(QGraphicsScene *scene, MoveStrategy *moveStrategy)
    : MovableObject(scene, moveStrategy)
{
}

void SpawnObject::setStartObjectPos()
{
    int randomNumber = rand() % static_cast<int>(scene()->width() - pixmap().width());
    setPos(randomNumber, 0 - pixmap().height());
}
