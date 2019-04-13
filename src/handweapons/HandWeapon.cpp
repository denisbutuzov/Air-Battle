#include "PresetPositionBuilder.h"
#include "Gunshell.h"

#include "HandWeapon.h"

HandWeapon::HandWeapon(const std::shared_ptr<QGraphicsScene> &scene)
    : scene_(scene)
{
}

std::unique_ptr<Gunshell> HandWeapon::shoot(qreal x, qreal y)
{
    PresetPositionBuilder builder;
    return builder.buildGunshell(scene_, 10, 1, ":/images/images/Bullet.png", QPointF(x, y));
}
