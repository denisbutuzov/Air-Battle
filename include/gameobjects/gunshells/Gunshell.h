#pragma once

#include <QMediaPlayer>

#include "MovableObject.h"

class Gunshell
        : public MovableObject
{
public:
    Gunshell(QGraphicsItem *parent = nullptr);
    Gunshell(qreal x, qreal y);
    virtual ~Gunshell() override;
    virtual void init(QGraphicsScene *scene) override final;
    unsigned int damage() const;
public slots:
    virtual void move() override final;
protected:
    void setDamage(unsigned int damage);
private:
    virtual void setDamage();
    virtual void setStartObjectPos() override final;
    virtual void setSpeed() override;
    virtual QString pathToSound() = 0;
    void playShotSound();
private:
    unsigned int damage_;
    QMediaPlayer *shotSound_;
    qreal startX_;
    qreal startY_;
};
