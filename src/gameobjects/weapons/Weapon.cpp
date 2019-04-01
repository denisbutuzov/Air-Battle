#include "PlayerObject.h"
#include "HandWeapon.h"

#include "Weapon.h"

Weapon::Weapon(const std::shared_ptr<QGraphicsScene> &scene,
               std::unique_ptr<MoveStrategy> &&moveStrategy)
    : MovableObject(scene, std::move(moveStrategy))
{
}

void Weapon::onMeetOtherObject(GameObject *otherObject)
{
    if(auto *player = dynamic_cast<PlayerObject *>(otherObject))
    {
        player->takeWeapon(handWeapon());
        destroy();
    }
}

std::unique_ptr<HandWeapon> Weapon::handWeapon()
{
    return std::make_unique<HandWeapon>(scene());
}
