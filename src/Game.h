#pragma once

#include <QGraphicsView>
#include <QTimer>

#include <memory>

#include "SpecialObjects/Observers/LabelObserver.h"

class PlayerObject;
class MovableObject;
class Level;

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
    void removeObjectsFromScene();
    void levelChange();
private:
    std::shared_ptr<QGraphicsScene> scene_;
    std::unique_ptr<PlayerObject> player_;
    std::shared_ptr<Level> level_;
    std::shared_ptr<LabelObserver<Level>> levelObserver_;
    std::list<std::shared_ptr<MovableObject>> objects_;
    QTimer spawnObjectTimer_;
    QTimer removeObjectTimer_;
    QTimer levelChangeTimer_;
    QTimer moveTimer_;
};
