#pragma once

#include <QGraphicsRectItem>
#include <QMediaPlayer>
#include <QObject>

class Bullet: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
private:
    QMediaPlayer *boomsound_;
public:
    Bullet();
public slots:
    void move();
};
