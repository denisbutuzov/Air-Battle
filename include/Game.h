#pragma once

#include <QGraphicsView>

#include "PlayerObject.h"

class Game
        : public QGraphicsView
{
    Q_OBJECT
public:
    Game(QWidget *parent = nullptr);
public slots:
    void spawn();
private:
    QGraphicsScene *scene_;
    PlayerObject *player_;
};
