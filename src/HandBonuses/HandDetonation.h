#pragma once

#include "HandBonus.h"

class HandDetonation
        : public HandBonus
{
public:
    HandDetonation(PlayerObject *player, GameObjectStorage *storage);
    virtual ~HandDetonation() override = default;
    virtual void execute() override;
};
