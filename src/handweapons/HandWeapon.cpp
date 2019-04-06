#include "Gunshell.h"

#include "HandWeapon.h"

HandWeapon::HandWeapon(const std::shared_ptr<QGraphicsScene> &scene)
    : scene_(scene)
{
}

std::unique_ptr<Gunshell> HandWeapon::shoot(qreal x, qreal y)
{
    auto gunshell = std::make_unique<Gunshell>(scene_);
    gunshell->setPixmap(QPixmap(":/images/images/Bullet.png"));
    gunshell->setSpeed(10);
    gunshell->setDamage(1);
    gunshell->setPos(x, y);
    return gunshell;
}
