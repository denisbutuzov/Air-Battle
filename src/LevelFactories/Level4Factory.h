#pragma once

#include "AbstractLevelFactory.h"

class Level4Factory
        : public AbstractLevelFactory
{
public:
    Level4Factory(std::weak_ptr<QGraphicsScene> scene);
    virtual ~Level4Factory() override = default;
    virtual std::unique_ptr<Enemy> enemy() override final;
    virtual std::unique_ptr<Weapon> weapon() override final;
};
