#pragma once

#include "AbstractVisitor.h"

/*!
 * \ingroup Visitors
 * \brief Класс посетителя, перемещающего игровые объекты.
 *
 * Реализует перемещение игровых объектов по сцене во время посещения.
 */
class MoveVisitor
        : public AbstractVisitor
{
public:
    ///Конструктор по умолчанию.
    MoveVisitor() = default;
    ///Деструктор по умолчанию.
    virtual ~MoveVisitor() override = default;
    ///Метод посещения и перемещения класса *Enemy*.
    virtual void visitEnemy(Enemy *enemy) override final;
    ///Метод посещения и перемещения класса *Weapon*.
    virtual void visitWeapon(Weapon *weapon) override final;
    ///Метод посещения и перемещения класса *Gunshell*.
    virtual void visitGunshell(Gunshell *gunshell) override final;
    ///Метод посещения и перемещения класса *Bonus*.
    virtual void visitBonus(Bonus *bonus) override final;
};
