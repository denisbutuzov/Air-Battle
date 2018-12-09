#include "PlayerObject.h"

#include "Weapon.h"

Weapon::Weapon(QGraphicsItem *parent)
    : SpawnObject(parent)
{
}

void Weapon::move()
{
    SpawnObject::move();

    //find colliding items
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i < n; i++)
    {
        if(PlayerObject *player = dynamic_cast<PlayerObject *>(colliding_items[i]))
        {
            player->takeWeapon(handWeapon());
            destroy();
        }
    }
}

void Weapon::setSpeed()
{
    MovableObject::setSpeed(4);
}
