#include "GameObjects/Enemies/Enemy.h"
#include "GameObjects/Weapons/Weapon.h"
#include "GameObjects/Gunshells/Gunshell.h"
#include "Visitors/AbstractVisitor.h"

#include "GameObjectKeeper.h"

template<typename ToClass, typename FromClass>
std::unique_ptr<ToClass> dynamic_unique_cast(std::unique_ptr<FromClass> &&from)
{
    if(ToClass *to = dynamic_cast<ToClass *>(from.get()))
    {
        std::unique_ptr<ToClass> result(to);
        from.release();
        return result;
    }
    return std::unique_ptr<ToClass>(nullptr);
}

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
    for(auto iter = std::begin(enemies_); iter != std::end(enemies_); ++iter)
    {
        (*iter)->accept(visitor);
    }
}

void GameObjectKeeper::acceptToWeapons(AbstractVisitor &visitor)
{
    for(auto iter = std::begin(weapons_); iter != std::end(weapons_); ++iter)
    {
        (*iter)->accept(visitor);
    }
}

void GameObjectKeeper::acceptToGunshells(AbstractVisitor &visitor)
{
    for(auto iter = std::begin(gunshells_); iter != std::end(gunshells_); ++iter)
    {
        (*iter)->accept(visitor);
    }
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
