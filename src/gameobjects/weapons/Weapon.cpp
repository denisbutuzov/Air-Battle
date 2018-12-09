#include "Weapon.h"

Weapon::Weapon(QGraphicsItem *parent)
    : SpawnObject(parent)
{
}

void Weapon::setSpeed()
{
    MovableObject::setSpeed(4);
}
