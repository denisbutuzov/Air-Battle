#include "HandWeapons/HandBazooka.h"

#include "Bazooka.h"

Bazooka::Bazooka(const std::shared_ptr<QGraphicsScene> &scene,
                 const std::shared_ptr<MoveStrategy> &moveStrategy)
    : Weapon(scene, std::move(moveStrategy))
{
}

std::unique_ptr<HandWeapon> Bazooka::handWeapon()
{
    return std::make_unique<HandBazooka>(scene());
}
