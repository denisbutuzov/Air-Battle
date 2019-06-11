#pragma once

#include <set>

#include "GameObject.h"

class HandWeapon;
class Gunshell;

class PlayerObject
        : public QObject
        , public GameObject
{
    Q_OBJECT

public:
    PlayerObject(std::weak_ptr<QGraphicsScene> scene);
    virtual ~PlayerObject() override;
    void takeWeapon(std::unique_ptr<HandWeapon> &&weapon);
    std::unique_ptr<Gunshell> shoot() const;
signals:
    void shot_sig();
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
    std::unique_ptr<HandWeapon> weapon_;
    bool timerAtWork_;
};
