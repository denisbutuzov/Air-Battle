#include "HandWeapon.h"

HandWeapon::HandWeapon(const std::shared_ptr<QGraphicsScene> &scene)
    : scene_(scene)
{
}

std::shared_ptr<QGraphicsScene> &HandWeapon::scene()
{
    return scene_;
}
