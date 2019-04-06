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

private:
    std::unique_ptr<MovableObject> createSpawnObject(AbstractLevelFactory &factory);

private:
    using listOfMovableObjects = std::list<std::unique_ptr<MovableObject>>;

    std::shared_ptr<QGraphicsScene> scene_;
    std::unique_ptr<PlayerObject> player_;
    std::unique_ptr<QTimer> spawnObjectTimer_;
    listOfMovableObjects enemies_;
    listOfMovableObjects gunshells_;
};
