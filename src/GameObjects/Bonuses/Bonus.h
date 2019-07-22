#pragma once

#include "GameObjects/MovableObject.h"

class HandBonus;
class PlayerObject;
class GameObjectStorage;

/*!
 * \ingroup Game_objects
 * \brief Абстрактный родительский класс всех игровых бонусов.
 *
 * Реализует класс бонуса, который может подобрать игрок.
 *
 * \todo
 * - класс бонуса, замораживающего врагов на игровой сцене;
 * - класс бонуса, отталкивающегшо мощным импульсом врагов на несколько позиций назад.
 */
class Bonus
        : public MovableObject
{
public:
    ///Деструктор по умолчанию.
    virtual ~Bonus() override = default;
    ///Метод, принимающий объект посетителя.
    virtual void accept(AbstractVisitor &visitor) override final;
    ///Метод, порождающий соответствующий объект ручного бонуса.
    virtual std::unique_ptr<HandBonus> handBonus(PlayerObject *player, GameObjectStorage *storage) = 0;
protected:
    ///Конструктор с двумя аргументами.
    Bonus(std::weak_ptr<QGraphicsScene> scene,
           std::shared_ptr<MoveStrategy> moveStrategy);
};
