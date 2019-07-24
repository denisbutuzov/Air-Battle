#pragma once

#include "HandBonus.h"

/*!
 * \ingroup Hand_bonuses
 * \brief Класс ручного взрывающего бонуса.
 *
 * Реализует класс ручного взрываюещего при использовании
 * всех находящихся на игровой сцене врагов.
 */
class HandDetonation
        : public HandBonus
{
public:
    ///Конструктор с двумя аргументами.
    HandDetonation(PlayerObject *player, GameObjectStorage *storage);
    ///Деструктор по умолчанию.
    virtual ~HandDetonation() override = default;
    ///Метод использования взрывающего бонуса.
    virtual void execute() override;
};
