#pragma once

#include <set>

#include "GameObject.h"

class HandWeapon;
class HandBonus;
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
    void setEquipment(std::shared_ptr<Equipment> equipment);
    void takeWeapon(std::unique_ptr<HandWeapon> &&weapon);
    void takeBonus(std::unique_ptr<HandBonus> &&bonus);
    std::unique_ptr<Gunshell> shoot() const;
    void execute();
    void reloadWeapon();
    void changeWeapon();
    void stepLeft();
    void stepRight();
    void stepUp();
    void stepDown();
signals:
    void shot_sig();
private:
    virtual void keyPressEvent(QKeyEvent *event) override final;
    virtual void keyReleaseEvent(QKeyEvent *event) override final;
    virtual void timerEvent(QTimerEvent *event) override final;
private:
    std::set<Qt::Key> pressedKeys_;
    std::shared_ptr<Equipment> equipment_;
    bool pressKeysTimerAtWork_;
    std::unique_ptr<HandBonus> bonus_;
};
