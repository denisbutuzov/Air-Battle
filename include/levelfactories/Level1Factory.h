#pragma once

#include "AbstractLevelFactory.h"

class Level1Factory
        : public AbstractLevelFactory
{
public:
    Level1Factory(const std::shared_ptr<QGraphicsScene> &scene);
    virtual ~Level1Factory() override = default;
    virtual std::unique_ptr<Enemy> enemy() override final;
    virtual std::unique_ptr<Weapon> weapon() override final;
};
