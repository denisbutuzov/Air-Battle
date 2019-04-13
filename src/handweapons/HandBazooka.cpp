#include "Gunshell.h"
#include "PresetPositionBuilder.h"

#include "HandBazooka.h"

HandBazooka::HandBazooka(const std::shared_ptr<QGraphicsScene> &scene)
    : HandWeapon(scene)
{
}

std::unique_ptr<Gunshell> HandBazooka::shoot(qreal x, qreal y)
{
    PresetPositionBuilder builder;
    return builder.buildGunshell(scene(), 10, 1, ":/images/images/rocket.png", QPointF(x, y));
}
