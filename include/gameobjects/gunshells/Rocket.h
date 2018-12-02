#pragma once

#include "GunShell.h"

class Rocket
        : public GunShell
{
public:
    Rocket(QGraphicsItem *parent = nullptr);
private:
    virtual void setObjectImage() override final;
    virtual void setStartObjectPos() override final;
    virtual void setDamage() override final;
    virtual QString pathToSound() override final;
};
