#include "HandWeapons/HandBazooka.h"

#include "Bazooka.h"

/*!
 * \param scene Слабый указатель на объект сцены.
 * \param moveStrategy Указатель на разделяемый объект стратегии движения.
 */
Bazooka::Bazooka(std::weak_ptr<QGraphicsScene> scene,
                 std::shared_ptr<MoveStrategy> moveStrategy)
    : Weapon(scene, moveStrategy)
{
}

/*!
 * \return Указатель с исключительными правами владения объектом ручной базуки.
 */
std::unique_ptr<HandWeapon> Bazooka::handWeapon()
{
    return std::make_unique<HandBazooka>(scene());
}
