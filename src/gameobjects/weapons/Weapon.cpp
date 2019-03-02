#include "PlayerObject.h"

#include "Weapon.h"

Weapon::Weapon(QGraphicsScene &scene,
               MoveStrategy &&moveStrategy)
    : MovableObject(scene, std::move(moveStrategy))
{

}

void Weapon::onMeetOtherObject(GameObject *otherObject)
{
    if(auto *player = dynamic_cast<PlayerObject *>(otherObject))
    {
        player->takeWeapon(handWeapon());
        destroy(this);
    }
}

HandWeapon &Weapon::handWeapon()
{
}

