#pragma once

#include "Gunshell.h"

class Bullet
        : public Gunshell
{
public:
    Bullet(QGraphicsItem *parent = nullptr);
    Bullet(qreal x, qreal y);
private:
    virtual void setObjectImage() override final;
    virtual QString pathToSound() override final;
};
