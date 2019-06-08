#pragma once

#include <QGraphicsView>
#include <QTimer>

#include <memory>

#include "SpecialObjects/Observers/LabelObserver.h"
#include "GameObjectKeeper.h"

class PlayerObject;
class Score;
class Level;
class Health;
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
    QTimer spawnObjectTimer_;
    QTimer moveTimer_;
    QTimer checkCollisionTimer_;
    QTimer removeObjectTimer_;
    QTimer levelChangeTimer_;
    GameObjectKeeper objectKeeper_;
    Score *score_;
    Level *level_;
    Health *health_;
    LabelObserver<Level> *levelObserver_;
    LabelObserver<Score> *scoreObserver_;
    HealthObserver *healthObserver_;
};
