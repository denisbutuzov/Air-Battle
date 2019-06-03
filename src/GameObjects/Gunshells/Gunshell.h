#pragma once

#include "MoveStrategies/MoveByLine.h"
#include "GameObjects/MovableObject.h"

class Gunshell
        : public MovableObject
{
public:
    Gunshell(std::shared_ptr<QGraphicsScene> scene,
             const QString &pixmap,
             int damage = 1,
             std::shared_ptr<MoveStrategy> moveStrategy = std::make_shared<MoveByLine>(MoveStrategy::Direction::Up, 10));
    virtual ~Gunshell() override = default;
    virtual void accept(AbstractVisitor &visitor) override final;

    void setDamage(int damage);
    int damage() const;

private:
    int damage_;
};
