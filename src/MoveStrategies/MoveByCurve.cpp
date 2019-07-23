#include <cmath>

#include "GameObjects/MovableObject.h"

#include "MoveByCurve.h"

/*!
 * \param dir Направление движения объекта.
 * \param speed Скорость движения объекта.
 */
MoveByCurve::MoveByCurve(MoveStrategy::Direction dir,
                         unsigned int speed)
    : MoveStrategy(dir, speed)
{
}

/*!
 * \param object Игровой объекта для перемещения.
 *
 * Перемещает игровой объект по кривой синусоидальной линии
 * **вверх** или **вниз** в зависимости от направления движения.
 */
void MoveByCurve::move(MovableObject &object)
{
    if(direction() == Direction::Up)
    {
        object.setY(object.y() - speed());
    }
    else
    {
        object.setY(object.y() + speed());
    }
    object.setX(object.x() + 5 * std::sin(0.02 * object.y()));
}
