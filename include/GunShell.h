#pragma once

#include <QObject>
#include <QMediaPlayer>
#include <QGraphicsPixmapItem>

class GunShell: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    unsigned int gunShellSpeed_;
    QMediaPlayer shotSound_;
private:
    virtual ~GunShell() = default;
    virtual void setGunShellSpeed() = 0;
    virtual void setShotSound() = 0;
    virtual void loadGunShellSettings();
public slots:
    virtual void move();
};
