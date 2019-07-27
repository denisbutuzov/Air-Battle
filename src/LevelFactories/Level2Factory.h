#pragma once

#include "AbstractLevelFactory.h"

/*!
 * \ingroup Level_factories
 * \brief Фабричный класс второго уровня.
 *
 * Порождает игровые объекты для второго уровня игры.
 */
class Level2Factory
        : public AbstractLevelFactory
{
public:
    ///Конструктор с одним аргументом.
    Level2Factory(std::weak_ptr<QGraphicsScene> scene);
    ///Деструктор по умолчанию.
    virtual ~Level2Factory() override = default;
    ///Метод, возвращающий объект врага.
    virtual std::unique_ptr<Enemy> enemy() override final;
    ///Метод, возвращающий объект оружия.
    virtual std::unique_ptr<Weapon> weapon() override final;
};
