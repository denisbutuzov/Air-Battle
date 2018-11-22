#pragma once

#include "GunShell.h"

class Rocket: public GunShell
{
private:
    virtual void setSpeed() override final;
    virtual void setShotSound() override final;
    virtual void setPixmap() override final;
public:
    Rocket(QGraphicsItem *parent = nullptr);
};
