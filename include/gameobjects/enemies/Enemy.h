#pragma once

#include "MoveByLine.h"
#include "SpawnObject.h"

class Gunshell;
class PlayerObject;

class Enemy
        : public SpawnObject
{
public:
    virtual ~Enemy() override = default;
    virtual void init() override;

protected:
    Enemy(QGraphicsScene *scene, MoveStrategy *moveStrategy = new MoveByLine(MoveStrategy::DIRECTION::DOWN));
    virtual void OnLeaveFromScene() override;

    void setHitpoint(int16_t hitpoint);

private:
    virtual void setHitpoint() = 0;
    virtual void OnMeetOtherObject(GameObject *otherObject) override;
    virtual void onMeetPlayer(PlayerObject *player);
    virtual void onMeetGunshell(Gunshell *gunshell);

private:
    int16_t hitpoint_;
};
