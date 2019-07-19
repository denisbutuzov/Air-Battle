#include "GameObjectStorage.h"
#include "GameObjects/Enemies/Enemy.h"

#include "HandDetonation.h"

HandDetonation::HandDetonation(PlayerObject *player, GameObjectStorage *storage)
    : HandBonus(player, storage)
{
}

void HandDetonation::execute()
{
    storage()->enemies().clear();
}
