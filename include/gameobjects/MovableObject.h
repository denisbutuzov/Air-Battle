#pragma once

#include "GameObject.h"

class MovableObject
        : public QObject
        , public GameObject
{
    Q_OBJECT
public:
    MovableObject(QGraphicsItem *parent = nullptr);
    virtual void init(QGraphicsScene *scene) override;
public slots:
    virtual void move() = 0;
protected:
    void destroyObject(GameObject *object);
    unsigned int &speed();
private:
    virtual void setSpeed();
private:
    unsigned int speed_;
};
