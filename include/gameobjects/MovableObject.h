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

    void destroy();
    void setSpeed(unsigned int speed);
    unsigned int speed() const;

public slots:
    void move();

protected:
    MovableObject(const std::shared_ptr<QGraphicsScene> &scene,
                  std::unique_ptr<MoveStrategy> &&moveStrategy);
    virtual void onLeaveFromScene();

private:
    enum class LOCATION
    {
        ON_SCENE,
        BEHIND_SCENE
    };

    virtual LOCATION checkOnBackstage(MoveStrategy::DIRECTION dir);
    virtual void onMeetOtherObject(GameObject *otherObject) = 0;

private:
    std::unique_ptr<QTimer> moveTimer_;
    std::unique_ptr<MoveStrategy> moveStrategy_;
    unsigned int speed_;
};
