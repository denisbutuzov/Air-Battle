#pragma once

#include <set>

#include "GameObject.h"

class HandWeapon;
class Gunshell;
class Equipment;

class PlayerObject
        : public QObject
        , public GameObject
{
    Q_OBJECT

public:
    PlayerObject(std::weak_ptr<QGraphicsScene> scene);
    virtual ~PlayerObject() override;
    bool isReadyToShot() const;
    void takeWeapon(std::unique_ptr<HandWeapon> &&weapon);
    void changeWeapon();
    void reloadWeapon();
    void setEquipment(std::unique_ptr<Equipment> &&equipment);
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
    std::unique_ptr<Equipment> equipment_;
    bool timerAtWork_;
};
