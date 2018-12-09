#include "Machinegun.h"

Machinegun::Machinegun(QGraphicsItem *parent)
    : Weapon(parent)
{
}

void Machinegun::setObjectImage()
{
    setPixmap(QPixmap(":/images/images/machinegun.png"));
}
