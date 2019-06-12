#include "HandWeapons/HandBazooka.h"

#include "Bazooka.h"

Bazooka::Bazooka(std::weak_ptr<QGraphicsScene> scene,
                 std::shared_ptr<MoveStrategy> moveStrategy)
    : Weapon(scene, moveStrategy)
{
}

std::unique_ptr<HandWeapon> Bazooka::handWeapon()
{
    return std::make_unique<HandBazooka>(scene());
}
