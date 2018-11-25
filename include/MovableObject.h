#pragma once

#include "GameObject.h"

class MovableObject
        : public QObject
        , public GameObject
{
    Q_OBJECT
public:
    MovableObject(QGraphicsItem *parent = nullptr);
    virtual void show(QGraphicsScene *scene) override final;
public slots:
    virtual void move() = 0;
protected:
    unsigned int &speed();
private:
    virtual void setSpeed();
private:
    unsigned int speed_;
};
