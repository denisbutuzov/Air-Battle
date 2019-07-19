#pragma once

#include "GameObjects/MovableObject.h"

class HandBonus;
class PlayerObject;
class GameObjectStorage;

class Bonus
        : public MovableObject
{
public:
    virtual ~Bonus() override = default;
    virtual void accept(AbstractVisitor &visitor) override final;
    virtual std::unique_ptr<HandBonus> handBonus(PlayerObject *player, GameObjectStorage *storage) = 0;
protected:
    Bonus(std::weak_ptr<QGraphicsScene> scene,
           std::shared_ptr<MoveStrategy> moveStrategy);
};
