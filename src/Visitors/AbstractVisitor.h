#pragma once

class Enemy;
class Gunshell;
class Weapon;
class Bonus;

/*!
 * \defgroup Visitors Посетители игровых объектов
 * \brief Данный модуль описывает посетителей игровых объектов.
 */

/*!
 * \ingroup Visitors
 * \brief Абстрактный родительский класс посетителей игровых объектов.
 *
 * Реализует одноименый шаблон проектирования **Посетитель**.
 */
class AbstractVisitor
{
public:
    ///Деструктор по умолчанию.
    virtual ~AbstractVisitor() = default;
    ///Метод посещения класса *Enemy*.
    virtual void visitEnemy(Enemy *enemy) = 0;
    ///Метод посещения класса *Weapon*.
    virtual void visitWeapon(Weapon *weapon) = 0;
    ///Метод посещения класса *Gunshell*.
    virtual void visitGunshell(Gunshell *gunshell) = 0;
    ///Метод посещения класса *Bonus*.
    virtual void visitBonus(Bonus *bonus) = 0;
protected:
    ///Конструктор по умолчанию.
    AbstractVisitor() = default;
};
