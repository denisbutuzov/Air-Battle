#pragma once

#include <memory>
#include <list>

class MovableObject;
class Enemy;
class Weapon;
class Gunshell;
class AbstractVisitor;

class GameObjectKeeper
{
public:
    using listOfEmemyObjects = std::list<std::shared_ptr<Enemy>>;
    using listOfWeaponObjects = std::list<std::shared_ptr<Weapon>>;
    using listOfGunshellObjects = std::list<std::shared_ptr<Gunshell>>;

    void pushMovableObject(std::unique_ptr<MovableObject> &&object);
    void pushEnemy(std::unique_ptr<Enemy> &&enemy);
    void pushWeapon(std::unique_ptr<Weapon> &&weapon);
    void pushGunshell(std::unique_ptr<Gunshell> &&gunshell);
    void acceptToAll(AbstractVisitor &visitor);
    void acceptToEnemies(AbstractVisitor &visitor);
    void acceptToWeapons(AbstractVisitor &visitor);
    void acceptToGunshells(AbstractVisitor &visitor);

    listOfEmemyObjects *enemies();
    listOfWeaponObjects *weapons();
    listOfGunshellObjects *gunshells();

private:
    listOfEmemyObjects enemies_;
    listOfWeaponObjects weapons_;
    listOfGunshellObjects gunshells_;
};
