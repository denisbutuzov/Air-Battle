#include "HandWeapons/HandMachinegun.h"

#include "Machinegun.h"

/*!
 * \param scene Слабый указатель на объект сцены.
 * \param moveStrategy Указатель на разделяемый объект стратегии движения.
 */
Machinegun::Machinegun(std::weak_ptr<QGraphicsScene> scene,
                       std::shared_ptr<MoveStrategy> moveStrategy)
    : Weapon(scene, moveStrategy)
{
}

/*!
 * \return Указатель с исключительными правами владения объектом ручного пулемета.
 */
std::unique_ptr<HandWeapon> Machinegun::handWeapon()
{
    return std::make_unique<HandMachinegun>(scene());
}
