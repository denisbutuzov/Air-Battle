#pragma once

#include <memory>
#include <list>

class MovableObject;
class Enemy;
class Bonus;
class Weapon;
class Gunshell;
class AbstractVisitor;

/*!
 * \brief Класс хранилища игровых объектов.
 *
 * Реализует хранилище игровых объектов.
 */
class GameObjectStorage
{
public:
    ///Метод добавления способного к перемещению объекта в хранилище.
    void pushMovableObject(std::unique_ptr<MovableObject> &&object);
    ///Метод добавления объекта врага в хранилище.
    void pushEnemy(std::unique_ptr<Enemy> &&enemy);
    ///Метод добавления объекта оружия в хранилище.
    void pushWeapon(std::unique_ptr<Weapon> &&weapon);
    ///Метод добавления объекта оружейного снаряда в хранилище.
    void pushGunshell(std::unique_ptr<Gunshell> &&gunshell);
    ///Метод добавления объекта бонуса в хранилище.
    void pushBonus(std::unique_ptr<Bonus> &&bonus);
    ///Метод применения объекта посетителя ко всем хранящимся объектам в хранилище.
    void accept(AbstractVisitor &visitor);
    ///Метод применения объекта посетителя ко всем объектам врагов в хранилище.
    void acceptToEnemies(AbstractVisitor &visitor);
    ///Метод применения объекта посетителя ко всем объектам оружия в хранилище.
    void acceptToWeapons(AbstractVisitor &visitor);
    ///Метод применения объекта посетителя ко всем объектам оружейных снарядов в хранилище.
    void acceptToGunshells(AbstractVisitor &visitor);
    ///Метод применения объекта посетителя ко всем объектом бонусов в хранилище.
    void acceptToBonuses(AbstractVisitor &visitor);
    ///Метод, возвращающий связанный список объектов врагов.
    std::list<std::unique_ptr<Enemy>> &enemies();
    ///Метод, возвращающий связанный список объектов оружия.
    std::list<std::unique_ptr<Weapon>> &weapons();
    ///Метод, возвращающий связанный список объектов оружейных снарядов.
    std::list<std::unique_ptr<Gunshell>> &gunshells();
    ///Метод, возвращающий связанный список объектов бонусов.
    std::list<std::unique_ptr<Bonus> > &bonuses();
private:
    std::list<std::unique_ptr<Enemy>> enemies_;
    std::list<std::unique_ptr<Weapon>> weapons_;
    std::list<std::unique_ptr<Gunshell>> gunshells_;
    std::list<std::unique_ptr<Bonus>> bonuses_;
};
