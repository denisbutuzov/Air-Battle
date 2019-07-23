#pragma once

#include "MoveStrategy.h"

/*!
 * \ingroup Move_strategies
 * \brief Класс стратегии движени по кривой линии.
 *
 * Реализует стратегию движения по кривой синусоидальной линии
 * **вверх** или **вниз** в зависимости от направления движения.
 */
class MoveByCurve
        : public MoveStrategy
{
public:
    ///Конструктор с двумя аргументами.
    MoveByCurve(Direction dir, unsigned int);
    ///Метод перемещения игрового объекта.
    virtual void move(MovableObject &object) override final;
};
