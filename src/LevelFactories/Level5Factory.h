#pragma once

#include "AbstractLevelFactory.h"

class Level5Factory
        : public AbstractLevelFactory
{
public:
    Level5Factory(std::shared_ptr<QGraphicsScene> scene);
    virtual ~Level5Factory() override = default;
    virtual std::unique_ptr<Enemy> enemy() override final;
    virtual std::unique_ptr<Weapon> weapon() override final;
};
