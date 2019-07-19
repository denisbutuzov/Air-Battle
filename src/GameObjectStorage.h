#pragma once

#include <memory>
#include <list>

class MovableObject;
class Enemy;
class Bonus;
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
    void pushBonus(std::unique_ptr<Bonus> &&bonus);
    void accept(AbstractVisitor &visitor);
    void acceptToEnemies(AbstractVisitor &visitor);
    void acceptToWeapons(AbstractVisitor &visitor);
    void acceptToGunshells(AbstractVisitor &visitor);
    void acceptToBonuses(AbstractVisitor &visitor);
    std::list<std::unique_ptr<Enemy>> &enemies();
    std::list<std::unique_ptr<Weapon>> &weapons();
    std::list<std::unique_ptr<Gunshell>> &gunshells();
    std::list<std::unique_ptr<Bonus> > &bonuses();
private:
    std::list<std::unique_ptr<Enemy>> enemies_;
    std::list<std::unique_ptr<Weapon>> weapons_;
    std::list<std::unique_ptr<Gunshell>> gunshells_;
    std::list<std::unique_ptr<Bonus>> bonuses_;
};
