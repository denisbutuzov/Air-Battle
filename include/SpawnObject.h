#pragma once

#include <QObject>
#include <QGraphicsPixmapItem>

#include "TypeInfoWrapper.h"

class SpawnObject: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    SpawnObject(QGraphicsItem *parent = nullptr);
public slots:
    virtual void move();
private:
    virtual void setSpeed();
    virtual void setObjectImage() = 0;
private:
    unsigned int speed_;
};
