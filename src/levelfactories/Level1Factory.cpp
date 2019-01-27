#include "Machinegun.h"
#include "Enemy1.h"
#include "Enemy2.h"

#include "Level1Factory.h"

Level1Factory::Level1Factory(QGraphicsScene *scene)
    : AbstractLevelFactory(scene)
{
}

Enemy *Level1Factory::enemy() const
{
    QVector<std::function<Enemy*()>> enemyCreatingVector
    {
         {[&](){return new Enemy1(scene());}},
         {[&](){return new Enemy2(scene());}}
    };

    return enemyCreatingVector[rand() % enemyCreatingVector.size()]();
}

Weapon *Level1Factory::weapon() const
{
    return new Machinegun(scene());
}
