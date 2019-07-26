#include "HandBonuses/HandDetonation.h"

#include "Detonation.h"

/*!
 * \param scene Слабый указатель на объект сцены.
 * \param moveStrategy Указатель на разделяемый объект стратегии движения.
 */
Detonation::Detonation(std::weak_ptr<QGraphicsScene> scene,
                       std::shared_ptr<MoveStrategy> moveStrategy)
    : Bonus(scene, moveStrategy)
{
}

/*!
 * \param player Указатель на объект, управляемый игроком.
 * \param storage Указатель на объект хранилища игровых объектов сцены.
 *
 * \return Указатель с исключительными правами владения объектом ручного взрывающего бонуса.
 */
std::unique_ptr<HandBonus> Detonation::handBonus(PlayerObject *player, GameObjectStorage *storage)
{
    return std::make_unique<HandDetonation>(player, storage);
}
