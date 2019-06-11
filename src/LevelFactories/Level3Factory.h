#pragma once

#include "AbstractLevelFactory.h"

class Level3Factory
        : public AbstractLevelFactory
{
public:
    Level3Factory(std::weak_ptr<QGraphicsScene> scene);
    virtual ~Level3Factory() override = default;
    virtual std::unique_ptr<Enemy> enemy() override final;
    virtual std::unique_ptr<Weapon> weapon() override final;
};
