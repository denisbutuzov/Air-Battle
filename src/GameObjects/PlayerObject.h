#pragma once

#include <set>

#include "GameObject.h"

class Magazine;
class HandWeapon;
class Gunshell;

constexpr double SCENE_PART_TO_NOT_MOVE = 0.66;

class PlayerObject
        : public QObject
        , public GameObject
{
    Q_OBJECT

public:
    PlayerObject(std::shared_ptr<QGraphicsScene> scene,
                 const QString &pixmap);
    virtual ~PlayerObject() override;

    void takeWeapon(std::unique_ptr<HandWeapon> &&weapon);
    void changeWeapon();
    void reloadWeapon();
    void setMagazine(std::unique_ptr<Magazine> &&magazine);
    std::unique_ptr<Gunshell> shoot() const;

signals:
    void shoot_sig();

private:
    virtual void keyPressEvent(QKeyEvent *event) override final;
    virtual void keyReleaseEvent(QKeyEvent *event) override final;

    void stepLeft();
    void stepRight();
    void stepUp();
    void stepDown();

private:
    std::unique_ptr<Magazine> weapons_;
    std::set<int> pressedKeys_;
};
