#include "HandBazooka.h"

#include "Bazooka.h"

Bazooka::Bazooka(QGraphicsItem *parent)
    : Weapon(parent)
{
}

void Bazooka::setObjectImage()
{
    setPixmap(QPixmap(":/images/images/bazooka.png"));
}

IHandWeapon *Bazooka::handWeapon()
{
    return new HandBazooka();
}
