#include "GameObjects/MovableObject.h"

#include "MoveByLine.h"

/*!
 * \param dir Направление движения объекта.
 * \param speed Скорость движения объекта.
 */
MoveByLine::MoveByLine(MoveStrategy::Direction dir,
                       unsigned int speed)
    : MoveStrategy(dir, speed)
{
}

/*!
 * \param object Игровой объекта для перемещения.
 *
 * Перемещает игровой объект вдоль прямой линии **вверх** или
 * **вниз** в зависимости от направления движения.
 */
void MoveByLine::move(MovableObject &object)
{
    if(direction() == Direction::Up)
    {
        object.setY(object.y() - speed());
    }
    else
    {
        object.setY(object.y() + speed());
    }
}
