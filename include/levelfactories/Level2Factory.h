#pragma once

#include "AbstractLevelFactory.h"

class Level2Factory
        : public AbstractLevelFactory
{
public:
    Level2Factory(QGraphicsScene *scene);
    virtual ~Level2Factory() override = default;

    virtual Enemy *enemy() const override final;
    virtual Weapon *weapon() const override final;
};
