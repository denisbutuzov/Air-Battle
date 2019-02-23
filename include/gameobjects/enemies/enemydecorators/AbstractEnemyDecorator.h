#pragma once

#include "Enemy.h"

class AbstractEnemyDecorator
        : public Enemy
{
public:
    virtual ~AbstractEnemyDecorator() override = default;
    virtual void init() override;

protected:
    AbstractEnemyDecorator(QGraphicsScene *scene, Enemy *enemy);

    Enemy *enemy() const;

private:
    Enemy *enemy_;
};
