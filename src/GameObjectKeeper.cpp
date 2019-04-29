#include "GameObjects/Enemies/Enemy.h"
#include "GameObjects/Weapons/Weapon.h"
#include "GameObjects/Gunshells/Gunshell.h"

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

void GameObjectKeeper::pushMovableObject(std::unique_ptr<MovableObject> &object)
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

void GameObjectKeeper::pushEnemy(std::unique_ptr<Enemy> &enemy)
{
    enemies_.push_back(std::move(enemy));
}

void GameObjectKeeper::pushWeapon(std::unique_ptr<Weapon> &weapon)
{
    weapons_.push_back(std::move(weapon));
}

void GameObjectKeeper::pushGunshell(std::unique_ptr<Gunshell> &gunshell)
{
    gunshells_.push_back(std::move(gunshell));
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
