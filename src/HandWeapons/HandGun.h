#pragma once

#include "HandWeapon.h"

/*!
 * \ingroup Hand_weapons
 * \brief Класс ручного пистолета.
 *
 * Реализует класс ручного пистолета.
 */
class HandGun
        : public HandWeapon
{
public:
    ///Конструктор с одним аргументом.
    HandGun(std::weak_ptr<QGraphicsScene> scene);
    ///Деструктор по умолчанию.
    virtual ~HandGun() override = default;
    ///Метод, проверяющий на безлимитное количество патронов.
    virtual bool unlimitedPatrons() const override final;
private:
    ///Метод, реализующий создание оружейного снаряда.
    virtual std::unique_ptr<Gunshell> createGunshell(qreal x, qreal y) override final;
};
