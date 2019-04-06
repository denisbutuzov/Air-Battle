#pragma once

#include "MoveByLine.h"
#include "MovableObject.h"

class Gunshell;

class Enemy
        : public MovableObject
{
public:
    Enemy(const std::shared_ptr<QGraphicsScene> &scene,
          std::unique_ptr<MoveStrategy> &&moveStrategy = std::make_unique<MoveByLine>(MoveStrategy::DIRECTION::DOWN));
    virtual ~Enemy() override = default;

    void setHitpoint(unsigned int hitpoint);
    unsigned int hitpoint() const;

private:
    unsigned int hitpoint_;
};
