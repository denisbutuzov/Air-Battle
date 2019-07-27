#pragma once

#include "HandWeapon.h"

/*!
 * \ingroup Hand_weapons
 * \brief Класс ручной базуки.
 *
 * Реализует класс ручной базуки.
 */
class HandBazooka
        : public HandWeapon
{
public:
    ///Конструктор с одним аргументом.
    HandBazooka(std::weak_ptr<QGraphicsScene> scene);
    ///Деструктор по умолчанию.
    virtual ~HandBazooka() override = default;
private:
    ///Метод, реализующий создание оружейного снаряда.
    virtual std::unique_ptr<Gunshell> createGunshell(qreal x, qreal y) override final;
};
