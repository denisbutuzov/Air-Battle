#pragma once

#include <QGraphicsScene>
#include <QGraphicsView>

#include "PlayerObject.h"
#include "Score.h"
#include "Health.h"

class Game
        : public QGraphicsView
{
    Q_OBJECT
public:
    Game(QWidget *parent = nullptr);
public slots:
    void spawn();
public:
    QGraphicsScene *scene_;
    PlayerObject *player_;
};
