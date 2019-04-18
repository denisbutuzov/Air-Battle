#pragma once

#include "MoveByLine.h"
#include "MovableObject.h"

class Gunshell
        : public MovableObject
{
public:
    Gunshell(const std::shared_ptr<QGraphicsScene> &scene,
             const std::shared_ptr<MoveStrategy> &moveStrategy = std::make_shared<MoveByLine>(MoveStrategy::DIRECTION::UP));
    virtual ~Gunshell() override = default;
    virtual void accept(AbstractVisitor &visitor) override;

    void setDamage(unsigned int damage);
    unsigned int damage() const;

private:
    unsigned int damage_;
};
