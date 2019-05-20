#pragma once

#include "GameObject.h"

class Magazine;
class HandWeapon;
class Gunshell;

class PlayerObject
        : public QObject
        , public GameObject
{
    Q_OBJECT

public:
    PlayerObject(const std::shared_ptr<QGraphicsScene> &scene,
                 const QString &pixmap);
    virtual ~PlayerObject() override;

    void takeWeapon(std::unique_ptr<HandWeapon> &&weapon);
    std::unique_ptr<Gunshell> shoot() const;

signals:
    void shoot_sig();

private:
    virtual void keyPressEvent(QKeyEvent *event) override final;

    void stepToLeft();
    void stepToRight();

private:
    std::unique_ptr<Magazine> weapons_;
};
