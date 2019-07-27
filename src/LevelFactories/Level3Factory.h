#pragma once

#include "AbstractLevelFactory.h"

/*!
 * \ingroup Level_factories
 * \brief Фабричный класс третьего уровня.
 *
 * Порождает игровые объекты для третьего уровня игры.
 */
class Level3Factory
        : public AbstractLevelFactory
{
public:
    ///Конструктор с одним аргументом.
    Level3Factory(std::weak_ptr<QGraphicsScene> scene);
    ///Деструктор по умолчанию.
    virtual ~Level3Factory() override = default;
    ///Метод, возвращающий объект врага.
    virtual std::unique_ptr<Enemy> enemy() override final;
    ///Метод, возвращающий объект оружия.
    virtual std::unique_ptr<Weapon> weapon() override final;
};
