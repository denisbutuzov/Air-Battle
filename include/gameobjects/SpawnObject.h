#pragma once

#include "MovableObject.h"

class SpawnObject
        : public MovableObject
{
public:
    virtual ~SpawnObject() override = default;

public slots:
    virtual void move() override;

protected:
    SpawnObject(QGraphicsScene *scene);

private:
    virtual void setStartObjectPos() override;
};
