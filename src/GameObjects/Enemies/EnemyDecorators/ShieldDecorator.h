#pragma once

#include "AbstractEnemyDecorator.h"

/*!
 * \ingroup Game_objects
 * \brief Класс щита для врага.
 *
 * Реализует класс защитного щита для врага.
 */
class ShieldDecorator
        : public AbstractEnemyDecorator
{
public:
    ///Конструктор с двумя аргументами.
    ShieldDecorator(std::unique_ptr<Enemy> enemy, int hitpoint = 1);
    ///Деструктор по умолчанию.
    virtual ~ShieldDecorator() override = default;
    ///Метод инициализации врага и защитного щита на сцене.
    virtual void init() override final;
    ///Метод перемещения врага и защитного щита.
    virtual void move() override final;
private:
    void initShield();
};
