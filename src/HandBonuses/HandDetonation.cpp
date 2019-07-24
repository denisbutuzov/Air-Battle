#include "GameObjectStorage.h"
#include "GameObjects/Enemies/Enemy.h"

#include "HandDetonation.h"

/*!
 * \param player Указатель на объект, управляемый игроком.
 * \param storage Указатель на объект хранилища игровых объектов сцены.
 */
HandDetonation::HandDetonation(PlayerObject *player, GameObjectStorage *storage)
    : HandBonus(player, storage)
{
}

/*!
 * Реализует уничтожение всех находящихся на сцене врагов.
 */
void HandDetonation::execute()
{
    storage()->enemies().clear();
}
