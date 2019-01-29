#pragma once

#include "GameObject.h"

class MovableObject
        : public QObject
        , public GameObject
{
    Q_OBJECT

public:
    virtual ~MovableObject() override = default;
    virtual void init() override;

    unsigned int speed() const;

public slots:
    virtual void move() = 0;

protected:
    MovableObject(QGraphicsScene *scene);

    void destroy();
    void destroy(GameObject *object);
    void setSpeed(unsigned int speed);

private:
    virtual void setSpeed();

private:
    unsigned int speed_;
};
