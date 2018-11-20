#pragma once

#include <QGraphicsScene>
#include <QGraphicsView>

#include "Player.h"
#include "Score.h"
#include "Health.h"

class Game: public QGraphicsView
{
public:
    QGraphicsScene *scene_;
    Player *player_;
    Score *score_;
    Health *health_;
public:
    Game(QWidget *parent = nullptr);
};
