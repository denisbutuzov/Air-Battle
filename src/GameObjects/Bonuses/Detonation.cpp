#include "HandBonuses/HandDetonation.h"

#include "Detonation.h"

Detonation::Detonation(std::weak_ptr<QGraphicsScene> scene,
                       std::shared_ptr<MoveStrategy> moveStrategy)
    : Bonus(scene, moveStrategy)
{
}

std::unique_ptr<HandBonus> Detonation::handBonus(PlayerObject *player, GameObjectStorage *storage)
{
    return std::make_unique<HandDetonation>(player, storage);
}
