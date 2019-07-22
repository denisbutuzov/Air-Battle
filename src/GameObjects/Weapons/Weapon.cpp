#include "Visitors/AbstractVisitor.h"

#include "Weapon.h"

/*!
 * \param scene Слабый указатель на объект сцены.
 * \param moveStrategy Указатель на разделяемый объект стратегии движения.
 */
Weapon::Weapon(std::weak_ptr<QGraphicsScene> scene,
               std::shared_ptr<MoveStrategy> moveStrategy)
    : MovableObject(scene, moveStrategy)
{
}

/*!
 * \param visitor Объект посетителя.
 *
 * Вызывает метод `void visitWeapon(Weapon *weapon)` переданного в качестве параметра
 * объекта посетителя.
 */
void Weapon::accept(AbstractVisitor &visitor)
{
    visitor.visitWeapon(this);
}
