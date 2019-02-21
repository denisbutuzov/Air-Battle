#pragma once

#include <QGraphicsView>

class SpawnObject;
class PlayerObject;
class ScoreObserver;
class HealthObserver;
class LevelObserver;
class AbstractLevelFactory;

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
