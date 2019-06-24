#include "Visitors/AbstractVisitor.h"

#include "Bonus.h"

Bonus::Bonus(std::weak_ptr<QGraphicsScene> scene,
             std::shared_ptr<MoveStrategy> moveStrategy)
    : MovableObject(scene, moveStrategy)
{
}

void Bonus::accept(AbstractVisitor &visitor)
{
    visitor.visitBonus(this);
}
