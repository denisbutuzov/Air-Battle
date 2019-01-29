#include "HandWeapon.h"

HandWeapon::HandWeapon(QGraphicsScene *scene)
    : scene_(scene)
{
}

QGraphicsScene *HandWeapon::scene() const
{
    return scene_;
}
