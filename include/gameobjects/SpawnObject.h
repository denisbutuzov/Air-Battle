#pragma once

#include "MovableObject.h"

class SpawnObject
        : public MovableObject
{
public:
    SpawnObject(QGraphicsItem *parent = nullptr);
public slots:
    virtual void move() override;
private:
    virtual void setStartObjectPos() override final;
};
