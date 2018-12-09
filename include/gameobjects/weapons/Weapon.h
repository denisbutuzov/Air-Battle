#pragma once

#include "SpawnObject.h"

class Weapon
        : public SpawnObject
{
public:
    Weapon(QGraphicsItem *parent = nullptr);
private:
    virtual void setSpeed() override final;
};


