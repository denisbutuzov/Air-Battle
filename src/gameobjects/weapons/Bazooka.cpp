#include "HandBazooka.h"

#include "Bazooka.h"

Bazooka::Bazooka(QGraphicsScene *scene)
    : Weapon(scene)
{
}

void Bazooka::setObjectImage()
{
    setPixmap(QPixmap(":/images/images/bazooka.png"));
}

HandWeapon *Bazooka::handWeapon()
{
    return new HandBazooka(scene());
}
