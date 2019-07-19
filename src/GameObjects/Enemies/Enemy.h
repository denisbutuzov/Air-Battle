#pragma once

#include "MoveStrategies/MoveByLine.h"
#include "GameObjects/MovableObject.h"

class Enemy
        : public MovableObject
{
public:
    enum class EnemyType
    {
        Enemy,
        Decorator
    };
public:
    Enemy(std::weak_ptr<QGraphicsScene> scene,
          int hitpoint = 1,
          std::shared_ptr<MoveStrategy> moveStrategy = std::make_shared<MoveByLine>(MoveStrategy::Direction::Down, 6));
    virtual ~Enemy() override;
    virtual void accept(AbstractVisitor &visitor) override;
    void setHitpoint(int hitpoint);
    int hitpoint() const;
protected:
    void setEnemyType(EnemyType type);
private:
    EnemyType enemyType() const;
private:
    int hitpoint_;
    EnemyType type_;
};
