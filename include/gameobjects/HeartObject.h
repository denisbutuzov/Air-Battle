#pragma once

#include <QPointF>

#include "GameObject.h"

const int WIDTH_BETWEEN_HEARTOBJECTS = 5;
const int WIDTH_SCALE_HEARTOBJECT = 30;
const int HEIGHT_SCALE_HEARTOBJECT = 30;

class Health;

class HeartObject
        : public GameObject
{
public:
    HeartObject(QGraphicsScene *scene, Health *parent);
    virtual ~HeartObject() override = default;

    QPointF coordinate() const;

private:
    virtual void setObjectImage() override final;
    virtual void setStartObjectPos() override final;

private:
    Health *parent_;
};
