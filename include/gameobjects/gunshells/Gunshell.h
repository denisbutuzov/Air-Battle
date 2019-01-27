#pragma once

#include <QMediaPlayer>

#include "MovableObject.h"

class Gunshell
        : public MovableObject
{
public:
    virtual ~Gunshell() override;

    virtual void init() override final;

    unsigned int damage() const;

public slots:
    virtual void move() override final;

protected:
    Gunshell(QGraphicsScene *scene, qreal x, qreal y);

    void setDamage(unsigned int damage);

private:
    virtual void setStartObjectPos() override final;
    virtual void setSpeed() override;
    virtual void setDamage();
    virtual QString pathToShotSound() const = 0;

    void playShotSound();

private:
    unsigned int damage_;
    QMediaPlayer *shotSound_;
    qreal x_;
    qreal y_;
};
