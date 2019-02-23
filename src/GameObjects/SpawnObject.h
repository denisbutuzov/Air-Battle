#pragma once

#include "MovableObject.h"

class SpawnObject
        : public MovableObject
{
public:
    virtual ~SpawnObject() override = default;

protected:
    SpawnObject(QGraphicsScene *scene, MoveStrategy *moveStrategy);

private:
    virtual void setStartObjectPos() override;
};
