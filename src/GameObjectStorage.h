#pragma once

#include <memory>
#include <list>

class MovableObject;
class Enemy;
class Weapon;
class Gunshell;
class AbstractVisitor;

class GameObjectStorage
{
public:
    void pushMovableObject(std::unique_ptr<MovableObject> &&object);
    void pushEnemy(std::unique_ptr<Enemy> &&enemy);
    void pushWeapon(std::unique_ptr<Weapon> &&weapon);
    void pushGunshell(std::unique_ptr<Gunshell> &&gunshell);
    void accept(AbstractVisitor &visitor);
    void acceptToEnemies(AbstractVisitor &visitor);
    void acceptToWeapons(AbstractVisitor &visitor);
    void acceptToGunshells(AbstractVisitor &visitor);
    std::list<std::shared_ptr<Enemy>> &enemies();
    std::list<std::shared_ptr<Weapon>> &weapons();
    std::list<std::shared_ptr<Gunshell>> &gunshells();
private:
    std::list<std::shared_ptr<Enemy>> enemies_;
    std::list<std::shared_ptr<Weapon>> weapons_;
    std::list<std::shared_ptr<Gunshell>> gunshells_;
};
