#pragma once

#include <QGraphicsScene>
#include <QGraphicsView>

#include "Player.h"
#include "Score.h"

class Game: public QGraphicsView
{
public:
    QGraphicsScene *scene_;
    Player *player_;
    Score *score_;
public:
    Game(QWidget *parent = nullptr);
};
