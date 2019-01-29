#pragma once

#include "AbstractEnemyDecorator.h"

class ShieldDecorator
        : public AbstractEnemyDecorator
{
public:
    ShieldDecorator(QGraphicsScene *scene, Enemy *enemy);
    virtual ~ShieldDecorator() override = default;

    virtual void init() override final;

private:
    virtual void setStartObjectPos() override final;
    virtual void setHitpoint() override final;
    virtual void setObjectImage() override final;
};
