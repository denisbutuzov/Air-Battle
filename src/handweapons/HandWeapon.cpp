#include "Gunshell.h"

#include "HandWeapon.h"

HandWeapon::HandWeapon(const std::shared_ptr<QGraphicsScene> &scene)
    : scene_(scene)
{
}

void HandWeapon::shoot(qreal x, qreal y)
{
    auto *gunshell = new Gunshell(scene_);
    gunshell->setPixmap(QPixmap(":/images/images/Bullet.png"));
    gunshell->setSpeed(10);
    gunshell->setDamage(1);
    gunshell->setPos(x, y);
    gunshell->init();
}
