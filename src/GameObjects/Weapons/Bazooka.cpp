#include "HandWeapons/HandBazooka.h"

#include "Bazooka.h"

Bazooka::Bazooka(std::shared_ptr<QGraphicsScene> scene,
                 const QString &pixmap,
                 std::shared_ptr<MoveStrategy> moveStrategy)
    : Weapon(scene, pixmap, moveStrategy)
{
}

std::unique_ptr<HandWeapon> Bazooka::handWeapon()
{
    return std::make_unique<HandBazooka>(scene());
}
