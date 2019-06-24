#pragma once

#include "MoveStrategies/MoveByLine.h"
#include "Bonus.h"

class Detonation
        : public Bonus
{
public:
    Detonation(std::weak_ptr<QGraphicsScene> scene,
               std::shared_ptr<MoveStrategy> moveStrategy = std::make_shared<MoveByLine>(MoveStrategy::Direction::Down, 6));
    virtual ~Detonation() override = default;
    virtual std::unique_ptr<HandBonus> handBonus(PlayerObject *player, GameObjectStorage *storage) override final;
};
