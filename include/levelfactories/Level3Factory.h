#pragma once

#include "AbstractLevelFactory.h"

class Level3Factory
        : public AbstractLevelFactory
{
public:
    Level3Factory(QGraphicsScene *scene);
    virtual ~Level3Factory() override = default;

    virtual Enemy *enemy() const override final;
    virtual Weapon *weapon() const override final;
};
