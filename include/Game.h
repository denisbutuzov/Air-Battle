#pragma once

#include <QGraphicsView>

#include "PlayerObject.h"
#include "ScoreObserver.h"
#include "HealthObserver.h"
#include "LevelObserver.h"
#include "AbstractLevelFactory.h"

class Game
        : public QGraphicsView
{
    Q_OBJECT
public:
    Game(QWidget *parent = nullptr);

private:
    SpawnObject *createSpawnObject(AbstractLevelFactory *factory);

private slots:
    void spawn();

private:
    QGraphicsScene *scene_;
    PlayerObject *player_;
    ScoreObserver *scoreObs_;
    HealthObserver *healthObs_;
    LevelObserver *levelObs_;
};
