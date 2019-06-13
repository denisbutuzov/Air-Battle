#pragma once

#include <QGraphicsView>
#include <QTimer>

#include <memory>

#include "GameObjectStorage.h"

template<typename T> class LabelObserver;
class HealthObserver;
class PlayerObject;
class Level;
class Score;
class Health;

class Game
        : public QGraphicsView
{
    Q_OBJECT

public:
    Game();
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
    std::shared_ptr<Level> level_;
    std::shared_ptr<Score> score_;
    std::shared_ptr<Health> health_;
    std::unique_ptr<LabelObserver<Level>> levelObserver_;
    std::unique_ptr<LabelObserver<Score>> scoreObserver_;
    std::unique_ptr<HealthObserver> healthObserver_;
    std::unique_ptr<PlayerObject> player_;
    GameObjectStorage objectsStorage_;
    QTimer spawnObjectTimer_;
    QTimer removeObjectTimer_;
    QTimer levelChangeTimer_;
    QTimer moveTimer_;
    QTimer checkCollisionTimer_;
};
