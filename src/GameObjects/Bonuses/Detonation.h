#pragma once

#include "MoveStrategies/MoveByLine.h"
#include "Bonus.h"

/*!
 * \ingroup Game_objects
 * \brief Класс взрывающего бонуса.
 *
 * Реализует класс бонуса, взрывающего всех врагов на игровой сцене.
 */
class Detonation
        : public Bonus
{
public:
    ///Конструктор с двумя аргументами.
    Detonation(std::weak_ptr<QGraphicsScene> scene,
               std::shared_ptr<MoveStrategy> moveStrategy = std::make_shared<MoveByLine>(MoveStrategy::Direction::Down, 6));
    ///Деструктор по умолчанию.
    virtual ~Detonation() override = default;
    ///Метод, пораждающий объект ручного взрывающего бонуса.
    virtual std::unique_ptr<HandBonus> handBonus(PlayerObject *player, GameObjectStorage *storage) override final;
};
