#pragma once

#include "HandWeapon.h"

/*!
 * \ingroup Hand_weapons
 * \brief Класс ручного пулемета.
 *
 * Реализует класс ручного пулемета.
 */
class HandMachinegun
        : public HandWeapon
{
public:
    ///Конструктор с одним аргументом.
    HandMachinegun(std::weak_ptr<QGraphicsScene> scene);
    ///Деструктор по умолчанию.
    virtual ~HandMachinegun() override = default;
private:
    ///Метод, реализующий создание оружейного снаряда.
    virtual std::unique_ptr<Gunshell> createGunshell(qreal x, qreal y) override final;
};
