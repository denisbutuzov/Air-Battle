#include "GameObjects/Enemies/Enemy.h"
#include "GameObjects/Weapons/Weapon.h"
#include "GameObjects/Gunshells/Gunshell.h"
#include "Visitors/AbstractVisitor.h"
#include "additionals.h"

#include "GameObjectKeeper.h"

void GameObjectKeeper::pushMovableObject(std::unique_ptr<MovableObject> &&object)
{
    if(auto enemy = dynamic_unique_cast<Enemy>(std::move(object)))
    {
        enemies_.push_back(std::move(enemy));
    }
    else if(auto weapon = dynamic_unique_cast<Weapon>(std::move(object)))
    {
        weapons_.push_back(std::move(weapon));
    }
    else if(auto gunshell = dynamic_unique_cast<Gunshell>(std::move(object)))
    {
        gunshells_.push_back(std::move(gunshell));
    }
}

void GameObjectKeeper::pushEnemy(std::unique_ptr<Enemy> &&enemy)
{
    enemies_.push_back(std::move(enemy));
}

void GameObjectKeeper::pushWeapon(std::unique_ptr<Weapon> &&weapon)
{
    weapons_.push_back(std::move(weapon));
}

void GameObjectKeeper::pushGunshell(std::unique_ptr<Gunshell> &&gunshell)
{
    gunshells_.push_back(std::move(gunshell));
}

void GameObjectKeeper::acceptToAll(AbstractVisitor &visitor)
{
    acceptToEnemies(visitor);
    acceptToWeapons(visitor);
    acceptToGunshells(visitor);
}

void GameObjectKeeper::acceptToEnemies(AbstractVisitor &visitor)
{
    std::for_each(std::begin(enemies_), std::end(enemies_), [&visitor](auto &obj){obj->accept(visitor);});
}

void GameObjectKeeper::acceptToWeapons(AbstractVisitor &visitor)
{
    std::for_each(std::begin(weapons_), std::end(weapons_), [&visitor](auto &obj){obj->accept(visitor);});
}

void GameObjectKeeper::acceptToGunshells(AbstractVisitor &visitor)
{
    std::for_each(std::begin(gunshells_), std::end(gunshells_), [&visitor](auto &obj){obj->accept(visitor);});
}

GameObjectKeeper::listOfEmemyObjects *GameObjectKeeper::enemies()
{
    return &enemies_;
}

GameObjectKeeper::listOfWeaponObjects *GameObjectKeeper::weapons()
{
    return &weapons_;
}

GameObjectKeeper::listOfGunshellObjects *GameObjectKeeper::gunshells()
{
    return &gunshells_;
}
