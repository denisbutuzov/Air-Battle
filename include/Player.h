#pragma once

#include <QGraphicsRectItem>
#include <QMediaPlayer>
#include <QObject>

class Player: public QObject, public QGraphicsRectItem
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
