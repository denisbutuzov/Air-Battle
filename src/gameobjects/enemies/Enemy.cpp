#include "Gunshell.h"
#include "PlayerObject.h"

#include "Enemy.h"

Enemy::Enemy(const std::shared_ptr<QGraphicsScene> &scene,
             std::unique_ptr<MoveStrategy> &&moveStrategy)
    : MovableObject(scene, std::move(moveStrategy))
{
}

void Enemy::setHitpoint(unsigned int hitpoint)
{
    hitpoint_ = hitpoint;
}

unsigned int Enemy::hitpoint() const
{
    return hitpoint_;
}

void Enemy::onMeetOtherObject(GameObject *otherObject)
{
    if(auto *gunshell = dynamic_cast<Gunshell *>(otherObject))
    {

    }
    else if(auto *player = dynamic_cast<PlayerObject *>(otherObject))
    {

    }
}
