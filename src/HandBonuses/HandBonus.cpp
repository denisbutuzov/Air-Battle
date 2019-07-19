#include "GameObjects/PlayerObject.h"
#include "GameObjectStorage.h"

#include "HandBonus.h"

HandBonus::HandBonus(PlayerObject *player, GameObjectStorage *storage)
    : player_(player)
    , storage_(storage)
{
}

PlayerObject *HandBonus::player() const
{
    return player_;
}

GameObjectStorage *HandBonus::storage() const
{
    return storage_;
}
