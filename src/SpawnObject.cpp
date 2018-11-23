#include <QGraphicsScene>

#include "SpawnObject.h"

void SpawnObject::findCollidingItems(QMap<QGraphicsItem *, std::function<void> > &matching)
{
    //find colliding items
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i < n; i++)
    {
        for(auto className : matching.uniqueKeys())
        {
            if(typeid(colliding_items[i]) == typeid(className))
            {
                matching.find(className).value();
            }
        }
    }
}

void SpawnObject::move()
{
    findCollidingItems();

    //move object down
    setPos(x(), y() + 5);

    //delete when object is behind the scene
    if(y() > scene()->height())
    {
        //remove from the scene
        scene()->removeItem(this);
        delete this;
    }
}
