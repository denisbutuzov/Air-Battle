#pragma once

#include "AbstractLevelFactory.h"

/*!
 * \ingroup Level_factories
 * \brief Фабричный класс пятого уровня.
 *
 * Порождает игровые объекты для пятого уровня игры.
 */
class Level5Factory
        : public AbstractLevelFactory
{
public:
    ///Конструктор с одним аргументом.
    Level5Factory(std::weak_ptr<QGraphicsScene> scene);
    ///Деструктор по умолчанию.
    virtual ~Level5Factory() override = default;
    ///Метод, возвращающий объект врага.
    virtual std::unique_ptr<Enemy> enemy() override final;
    ///Метод, возвращающий объект оружия.
    virtual std::unique_ptr<Weapon> weapon() override final;
};
