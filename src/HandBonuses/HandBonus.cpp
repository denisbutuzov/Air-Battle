#include "GameObjects/PlayerObject.h"
#include "GameObjectStorage.h"

#include "HandBonus.h"

/*!
 * \param player Указатель на объект, управляемый игроком.
 * \param storage Указатель на объект хранилища игровых объектов сцены.
 */
HandBonus::HandBonus(PlayerObject *player, GameObjectStorage *storage)
    : player_(player)
    , storage_(storage)
{
}

/*!
 * \return Указатель на объект, управляемый игроком.
 */
PlayerObject *HandBonus::player() const
{
    return player_;
}

/*!
 * \return Указатель на объект хранилища игровых объектов.
 */
GameObjectStorage *HandBonus::storage() const
{
    return storage_;
}
