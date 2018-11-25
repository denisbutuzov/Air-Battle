#pragma once

#include "MovableObject.h"

class SpawnObject
        : public MovableObject
{
public:
    SpawnObject(QGraphicsItem *parent = nullptr);
public slots:
    virtual void move() override final;
private:
    virtual void setSpeed() override;
    virtual void setObjectPos() override final;
};
