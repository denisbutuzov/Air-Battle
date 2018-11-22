#pragma once

#include <QGraphicsPixmapItem>
#include <QMediaPlayer>
#include <QObject>

class Bullet: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    QMediaPlayer *boomsound_;
public:
    Bullet();
public slots:
    void move();
};
