#pragma once

#include <QGraphicsPixmapItem>
#include <QMediaPlayer>
#include <QObject>

class Player: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player(QGraphicsItem *parent = nullptr);
    void keyPressEvent(QKeyEvent *event) override;
public slots:
    void spawn();
};
