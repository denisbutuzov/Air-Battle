#pragma once

#include "MoveByLine.h"
#include "MovableObject.h"

class Enemy
        : public MovableObject
{
public:
    Enemy(const std::shared_ptr<QGraphicsScene> &scene,
          const std::shared_ptr<MoveStrategy> &moveStrategy = std::make_shared<MoveByLine>(MoveStrategy::DIRECTION::DOWN));
    virtual ~Enemy() override = default;
    virtual void accept(AbstractVisitor &visitor) override;

    void setHitpoint(int hitpoint);
    int hitpoint() const;

private:
    int hitpoint_;
};
