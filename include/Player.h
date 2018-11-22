#pragma once

#include <QGraphicsPixmapItem>
#include <QMediaPlayer>
#include <QObject>

class Player: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    QMediaPlayer *bulletsound_;
public:
    Player(QGraphicsItem *parent = nullptr);
    void keyPressEvent(QKeyEvent *event) override;
public slots:
    void spawn();
};
