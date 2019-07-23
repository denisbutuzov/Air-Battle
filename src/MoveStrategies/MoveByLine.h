#pragma once

#include "MoveStrategy.h"

/*!
 * \ingroup Move_strategies
 * \brief Класс стратегии движения вдоль прямой линии.
 *
 * Реализует стратегию движения вдоль прямой линии **вверх** или
 * **вниз** в зависимости от направления движения.
 */
class MoveByLine
        : public MoveStrategy
{
public:
    ///Конструктор с двумя аргументами.
    MoveByLine(Direction dir, unsigned int speed);\
    ///Метод перемещения игрового объекта.
    virtual void move(MovableObject &object) override final;
};
