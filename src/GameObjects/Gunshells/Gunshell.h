#pragma once

#include "MoveStrategies/MoveByLine.h"
#include "GameObjects/MovableObject.h"

class Gunshell
        : public MovableObject
{
public:
    Gunshell(std::weak_ptr<QGraphicsScene> scene,
             int damage = 1,
             std::shared_ptr<MoveStrategy> moveStrategy = std::make_shared<MoveByLine>(MoveStrategy::Direction::Up, 20));
    virtual ~Gunshell() override = default;
    virtual void accept(AbstractVisitor &visitor) override final;
    void setDamage(int damage);
    int damage() const;
private:
    int damage_;
};
