#include "HandBazooka.h"

#include "Bazooka.h"

Bazooka::Bazooka(QGraphicsScene *scene, MoveStrategy *moveStrategy)
    : Weapon(scene, moveStrategy)
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
