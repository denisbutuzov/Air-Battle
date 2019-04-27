#include "GameObjects/Enemies/Enemy.h"
#include "GameObjects/Weapons/Weapon.h"
#include "GameObjects/Gunshells/Gunshell.h"

#include "GameObjectKeeper.h"

void GameObjectKeeper::pushMovableObject(std::unique_ptr<MovableObject> &object)
{
    if (auto *enemy = dynamic_cast<Enemy *>(object.get()))
    {
        std::unique_ptr<Enemy> upEnemy(enemy);
        object.release();
        enemies_.push_back(std::move(upEnemy));
    }
    else if (auto *weapon = dynamic_cast<Weapon *>(object.get()))
    {
        std::unique_ptr<Weapon> upWeapon(weapon);
        object.release();
        weapons_.push_back(std::move(upWeapon));
    }
    else if (auto *gunshell = dynamic_cast<Gunshell *>(object.get()))
    {
        std::unique_ptr<Gunshell> upGunshell(gunshell);
        object.release();
        gunshells_.push_back(std::move(upGunshell));
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
