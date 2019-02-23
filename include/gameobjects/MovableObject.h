#pragma once

#include "GameObject.h"
#include "MoveStrategy.h"

class MovableObject
        : public QObject
        , public GameObject
{
    Q_OBJECT

public:
    virtual ~MovableObject() override;
    virtual void init() override;

    uint16_t speed() const;
    MoveStrategy *moveStrategy() const;

public slots:
    void move();

protected:
    MovableObject(QGraphicsScene *scene, MoveStrategy *moveStrategy);
    virtual void OnLeaveFromScene();

    void destroy(GameObject *object);
    void setSpeed(uint16_t speed);

private:
    enum class LOCATION
    {
        ON_SCENE,
        BEHIND_SCENE
    };

    virtual void setSpeed();
    virtual LOCATION checkOnBackstage(MoveStrategy::DIRECTION dir);
    virtual void OnMeetOtherObject(GameObject *otherObject) = 0;

private:
    QTimer *moveObjectTimer_;
    MoveStrategy *moveStrategy_;
    uint16_t speed_;
};
