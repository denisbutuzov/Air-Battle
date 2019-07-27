#pragma once

#include "AbstractLevelFactory.h"

/*!
 * \ingroup Level_factories
 * \brief Фабричный класс четвертого уровня.
 *
 * Порождает игровые объекты для четвертого уровня игры.
 */
class Level4Factory
        : public AbstractLevelFactory
{
public:
    ///Конструктор с одним аргументом.
    Level4Factory(std::weak_ptr<QGraphicsScene> scene);
    ///Деструктор по умолчанию.
    virtual ~Level4Factory() override = default;
    ///Метод, возвращающий объект врага.
    virtual std::unique_ptr<Enemy> enemy() override final;
    ///Метод, возвращающий объект оружия.
    virtual std::unique_ptr<Weapon> weapon() override final;
};
