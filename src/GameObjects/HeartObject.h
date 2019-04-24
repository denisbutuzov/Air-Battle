#pragma once

#include "GameObject.h"

const int WIDTH_BETWEEN_HEARTOBJECTS = 5;
const int WIDTH_SCALE_HEARTOBJECT = 25;
const int HEIGHT_SCALE_HEARTOBJECT = 25;

class HealthObserver;

class HeartObject
        : public GameObject
{
public:
    HeartObject(QGraphicsScene *scene, HealthObserver *parent);
    virtual ~HeartObject() override = default;

    QPointF coordinate() const;

private:
    virtual void setObjectImage() override final;
    virtual void setStartObjectPos() override final;

private:
    HealthObserver *parent_;
};
