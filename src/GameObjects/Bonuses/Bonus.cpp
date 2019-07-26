#include "Visitors/AbstractVisitor.h"

#include "Bonus.h"

/*!
 * \param scene Слабый указатель на объект сцены.
 * \param moveStrategy Указатель на разделяемый объект стратегии движения.
 */
Bonus::Bonus(std::weak_ptr<QGraphicsScene> scene,
             std::shared_ptr<MoveStrategy> moveStrategy)
    : MovableObject(scene, moveStrategy)
{
}

/*!
 * \param visitor Объект посетителя.
 *
 * Вызывает метод `void visitBonus(Bonus *bonus)` переданного в качестве параметра
 * объекта посетителя.
 */
void Bonus::accept(AbstractVisitor &visitor)
{
    visitor.visitBonus(this);
}
