#pragma once

#include "MoveByLine.h"
#include "MovableObject.h"

class QMediaPlayer;

class Gunshell
        : public MovableObject
{
public:
    virtual ~Gunshell() override;
    virtual void init() override final;

    unsigned int damage() const;

protected:
    Gunshell(QGraphicsScene *scene, qreal x, qreal y, MoveStrategy *moveStrategy = new MoveByLine(MoveStrategy::DIRECTION::UP));

    void setDamage(unsigned int damage);

private:
    virtual void setStartObjectPos() override final;
    virtual void setSpeed() override;
    virtual void OnMeetOtherObject(GameObject *otherObject) override;
    virtual void setDamage();
    virtual QString pathToShotSound() const = 0;

    void playShotSound();

private:
    unsigned int damage_;
    QMediaPlayer *shotSound_;
    qreal x_;
    qreal y_;
};
