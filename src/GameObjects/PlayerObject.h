#pragma once

#include <set>

#include "GameObject.h"

class PlayerObject
        : public QObject
        , public GameObject
{
    Q_OBJECT

public:
    PlayerObject(std::weak_ptr<QGraphicsScene> scene);
    virtual ~PlayerObject() override = default;
private:
    virtual void keyPressEvent(QKeyEvent *event) override final;
    virtual void keyReleaseEvent(QKeyEvent *event) override final;
    virtual void timerEvent(QTimerEvent *event) override final;
    void stepLeft();
    void stepRight();
    void stepUp();
    void stepDown();
private:
    std::set<Qt::Key> pressedKeys_;
    bool timerAtWork_;
};
