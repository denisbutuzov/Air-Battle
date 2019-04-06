#pragma once

#include "MoveByLine.h"
#include "MovableObject.h"

class Gunshell
        : public MovableObject
{
public:
    Gunshell(const std::shared_ptr<QGraphicsScene> &scene,
             std::unique_ptr<MoveStrategy> &&moveStrategy = std::make_unique<MoveByLine>(MoveStrategy::DIRECTION::UP));
    virtual ~Gunshell() override = default;

    void setDamage(unsigned int damage);
    unsigned int damage() const;

private:
    unsigned int damage_;
};
