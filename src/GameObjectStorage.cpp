#include "GameObjects/Enemies/Enemy.h"
#include "GameObjects/Weapons/Weapon.h"
#include "GameObjects/Gunshells/Gunshell.h"
#include "Visitors/AbstractVisitor.h"
#include "additionals.h"

#include "GameObjectStorage.h"

void GameObjectStorage::pushMovableObject(std::unique_ptr<MovableObject> &&object)
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

void GameObjectStorage::pushEnemy(std::unique_ptr<Enemy> &&enemy)
{
    enemies_.push_back(std::move(enemy));
}

void GameObjectStorage::pushWeapon(std::unique_ptr<Weapon> &&weapon)
{
    weapons_.push_back(std::move(weapon));
}

void GameObjectStorage::pushGunshell(std::unique_ptr<Gunshell> &&gunshell)
{
    gunshells_.push_back(std::move(gunshell));
}

void GameObjectStorage::accept(AbstractVisitor &visitor)
{
    acceptToEnemies(visitor);
    acceptToWeapons(visitor);
    acceptToGunshells(visitor);
}

void GameObjectStorage::acceptToEnemies(AbstractVisitor &visitor)
{
    std::for_each(std::begin(enemies_), std::end(enemies_), [&visitor](auto &obj){ obj->accept(visitor); });
}

void GameObjectStorage::acceptToWeapons(AbstractVisitor &visitor)
{
    std::for_each(std::begin(weapons_), std::end(weapons_), [&visitor](auto &obj){ obj->accept(visitor); });
}

void GameObjectStorage::acceptToGunshells(AbstractVisitor &visitor)
{
    std::for_each(std::begin(gunshells_), std::end(gunshells_), [&visitor](auto &obj){ obj->accept(visitor); });
}

std::list<std::unique_ptr<Enemy>> &GameObjectStorage::enemies()
{
    return enemies_;
}

std::list<std::unique_ptr<Weapon> > &GameObjectStorage::weapons()
{
    return weapons_;
}

std::list<std::unique_ptr<Gunshell> > &GameObjectStorage::gunshells()
{
    return gunshells_;
}
