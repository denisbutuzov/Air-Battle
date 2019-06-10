#pragma once

#include "AbstractLevelFactory.h"

class Level2Factory
        : public AbstractLevelFactory
{
public:
    Level2Factory(std::weak_ptr<QGraphicsScene> scene);
    virtual ~Level2Factory() override = default;
    virtual std::unique_ptr<Enemy> enemy() override final;
    //virtual std::unique_ptr<Weapon> weapon() override final;
};
