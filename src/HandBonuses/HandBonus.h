#pragma once

class PlayerObject;
class GameObjectStorage;

class HandBonus
{
public:
    HandBonus(PlayerObject *player, GameObjectStorage *storage);
    virtual ~HandBonus() = default;
    virtual void execute() = 0;
protected:
    PlayerObject *player() const;
    GameObjectStorage *storage() const;
private:
    PlayerObject *player_;
    GameObjectStorage *storage_;
};
