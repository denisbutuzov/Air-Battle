#include "PlayerObject.h"

#include "Weapon.h"

Weapon::Weapon(QGraphicsScene *scene, MoveStrategy *moveStrategy)
    : SpawnObject(scene, moveStrategy)
{
}

void Weapon::setSpeed()
{
    MovableObject::setSpeed(4);
}

void Weapon::OnMeetOtherObject(GameObject *otherObject)
{
    if(auto *player = dynamic_cast<PlayerObject *>(otherObject))
    {
        player->takeWeapon(handWeapon());
        destroy(this);
    }
}
