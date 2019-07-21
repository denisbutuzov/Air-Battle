#include <QGraphicsScene>

#include "MoveStrategies/MoveStrategy.h"

#include "MovableObject.h"

/*!
 * \param scene Слабый указатель на объект сцены.
 * \param moveStrategy Указатель на разделяемый объект стратегии движения.
 */
MovableObject::MovableObject(std::weak_ptr<QGraphicsScene> scene,
                             std::shared_ptr<MoveStrategy> moveStrategy)
    : GameObject(scene)
    , moveStrategy_(moveStrategy)
{
}

/*!
 * Делегирует обязанности передвижения объекта стратегии движения,
 * в котором реализован соответствующий алгоритм движения.
 */
void MovableObject::move()
{
    moveStrategy_->move(*this);
}

/*!
 * \param speed Скорость движения объекта.
 *
 * Устанавливает скорость передвижения объекта путем установки скорости
 * движения объекту стратегии движения.
 */
void MovableObject::setSpeed(unsigned int speed)
{
    moveStrategy_->setSpeed(speed);
}

/*!
 * \return Скорость движения объекта.
 */
unsigned int MovableObject::speed() const
{
    return moveStrategy_->speed();
}

/*!
 * \return Указатель на разделяемый объект статегии движения.
 */
std::shared_ptr<MoveStrategy> MovableObject::moveStrategy() const
{
    return moveStrategy_;
}
