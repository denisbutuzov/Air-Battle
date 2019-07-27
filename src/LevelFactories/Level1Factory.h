#pragma once

#include "AbstractLevelFactory.h"

/*!
 * \ingroup Level_factories
 * \brief Фабричный класс первого уровня.
 *
 * Порождает игровые объекты для первого уровня игры.
 */
class Level1Factory
        : public AbstractLevelFactory
{
public:
    ///Конструктор с одним аргументом.
    Level1Factory(std::weak_ptr<QGraphicsScene> scene);
    ///Деструктор по умолчанию.
    virtual ~Level1Factory() override = default;
    ///Метод, возвращающий объект врага.
    virtual std::unique_ptr<Enemy> enemy() override final;
    ///Метод, возвращающий объект оружия.
    virtual std::unique_ptr<Weapon> weapon() override final;
};
