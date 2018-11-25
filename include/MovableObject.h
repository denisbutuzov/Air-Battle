#pragma once

#include "GameObject.h"

class MovableObject
        : public QObject
        , public GameObject
{
    Q_OBJECT
public:
    MovableObject(QGraphicsItem *parent = nullptr);
    virtual void draw(QGraphicsScene *scene);
public slots:
    virtual void move() = 0;
private:
    virtual void setSpeed() = 0;
private:
    unsigned int speed_;
};
