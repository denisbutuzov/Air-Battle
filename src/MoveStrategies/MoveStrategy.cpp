#include "MoveStrategy.h"

/*!
 * \param dir Направление движения объекта.
 * \param speed Скорость движения объекта.
 */
MoveStrategy::MoveStrategy(MoveStrategy::Direction dir,
                           unsigned int speed)
    : dir_(dir)
    , speed_(speed)
{
}

/*!
 * \return Направление движения объекта.
 */
MoveStrategy::Direction MoveStrategy::direction() const
{
    return dir_;
}

/*!
 * \param speed Скорость игрового объекта.
 *
 * Устанавливает скорость передвижения игрового объекта.
 */
void MoveStrategy::setSpeed(unsigned int speed)
{
    speed_ = speed;
}

/*!
 * \return Скорость движения объекта.
 */
unsigned int MoveStrategy::speed() const
{
    return speed_;
}
