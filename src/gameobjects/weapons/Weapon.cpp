#include <QGraphicsScene>

#include "PlayerObject.h"

#include "Weapon.h"

void Weapon::move()
{
    //destroy weapon
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i < n; i++)
    {
        if(typeid(*(colliding_items[i])) == typeid(Player))
        {
            scene()->removeItem(this);
            delete this;

            return;
        }
    }

    //move weapon down
    setPos(x(), y() + 5);

    //delete weapon
    if(y() > scene()->height())
    {
        //remove from the scene
        scene()->removeItem(this);
        delete this;
    }
}
