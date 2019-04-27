#pragma once

#include <QGraphicsView>
#include <memory>

#include "SpecialObjects/Observers/LabelObserver.h"
#include "GameObjectKeeper.h"

class Gunshell;
class PlayerObject;
class AbstractLevelFactory;
class Score;
class Level;
class Health;
class ScoreObserver;
class LevelObserver;
class HealthObserver;

class Game
        : public QGraphicsView
{
    Q_OBJECT

public:
    Game(QWidget *parent = nullptr);
    ~Game();

private slots:
    void moveGameObjects();
    void getSpawnObjectFromFactory();
    void getGunshellFromPlayer();
    void removeObjectsFromScene();
    void checkCollisionBetweenGameObjects();
    void levelChange();

private:
    std::shared_ptr<QGraphicsScene> scene_;
    std::unique_ptr<PlayerObject> player_;
    std::unique_ptr<QTimer> spawnObjectTimer_;
    std::unique_ptr<QTimer> removeObjectTimer_;
    std::unique_ptr<QTimer> checkCollisionTimer_;
    std::unique_ptr<QTimer> moveTimer_;
    std::unique_ptr<QTimer> levelChangeTimer_;
    GameObjectKeeper objectKeeper_;
    Score *score_;
    Level *level_;
    Health *health_;
    LabelObserver<Level> *levelObserver_;
    LabelObserver<Score> *scoreObserver_;
    HealthObserver *healthObserver_;

};
