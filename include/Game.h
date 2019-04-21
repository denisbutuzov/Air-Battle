#pragma once

#include <QGraphicsView>
#include <memory>

class Gunshell;
class PlayerObject;
class MovableObject;
class AbstractLevelFactory;
class Score;
class Level;
class ScoreObserver;
class LevelObserver;

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
    std::unique_ptr<MovableObject> createSpawnObject(std::unique_ptr<AbstractLevelFactory> &factory);

private:
    using listOfMovableObjects = std::list<std::shared_ptr<MovableObject>>;

    std::shared_ptr<QGraphicsScene> scene_;
    std::unique_ptr<PlayerObject> player_;
    std::unique_ptr<QTimer> spawnObjectTimer_;
    std::unique_ptr<QTimer> removeObjectTimer_;
    std::unique_ptr<QTimer> checkCollisionTimer_;
    std::unique_ptr<QTimer> moveTimer_;
    std::unique_ptr<QTimer> levelChangeTimer_;
    listOfMovableObjects enemies_;
    listOfMovableObjects weapons_;
    listOfMovableObjects gunshells_;
    Score *score_;
    Level *level_;
    ScoreObserver *scoreObserver_;
    LevelObserver *levelObserver_;
};
