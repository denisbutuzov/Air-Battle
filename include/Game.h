#pragma once

#include <QGraphicsView>

#include "PlayerObject.h"
#include "AbstractLevelFactory.h"

class Game
        : public QGraphicsView
{
    Q_OBJECT
public:
    Game(QWidget *parent = nullptr);

public slots:
    void spawn();

private:
    SpawnObject *callFactory(AbstractLevelFactory *factory);

private:
    QGraphicsScene *scene_;
    PlayerObject *player_;
};
