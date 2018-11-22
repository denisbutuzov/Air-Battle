#pragma once

#include <QObject>
#include <QMediaPlayer>
#include <QGraphicsPixmapItem>

class GunShell: public QObject, virtual public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    unsigned int speed_;
    QMediaPlayer shotSound_;
private:
    virtual void setSpeed() = 0;
    virtual void setShotSound() = 0;
    virtual void setPixmap() = 0;
protected:
    virtual void loadSettings();
    unsigned int &speed();
    QMediaPlayer &shotSound();
public slots:
    virtual void move();
};
