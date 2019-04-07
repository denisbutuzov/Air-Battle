#pragma once

#include <QGraphicsView>
#include <memory>

class Gunshell;
class PlayerObject;
class MovableObject;
class AbstractLevelFactory;

class Game
        : public QGraphicsView
{
    Q_OBJECT

public:
    Game(QWidget *parent = nullptr);
    ~Game();

private slots:
    void getSpawnObjectFromFactory();
    void getGunshellFromPlayer();
    void removeObjectsFromScene();
    void checkCollisionBetweenGameObjects();

private:
    std::unique_ptr<MovableObject> createSpawnObject(AbstractLevelFactory &factory);

private:
    using listOfMovableObjects = std::list<std::shared_ptr<MovableObject>>;

    std::shared_ptr<QGraphicsScene> scene_;
    std::unique_ptr<PlayerObject> player_;
    std::unique_ptr<QTimer> spawnObjectTimer_;
    std::unique_ptr<QTimer> removeObjectTimer_;
    std::unique_ptr<QTimer> checkCollisionTimer_;
    listOfMovableObjects enemies_;
    listOfMovableObjects gunshells_;
};
