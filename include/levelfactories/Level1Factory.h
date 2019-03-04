#pragma once

#include "AbstractLevelFactory.h"

class Level1Factory
        : public AbstractLevelFactory
{
public:
    Level1Factory(const std::shared_ptr<QGraphicsScene> &scene);
    virtual ~Level1Factory() override = default;
    virtual Enemy *enemy() override final;
};
