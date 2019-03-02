#pragma once

#include <QGraphicsView>
#include <memory>

class PlayerObject;
class MovableObject;

class Game
        : public QGraphicsView
{
    Q_OBJECT

public:
    Game(QWidget *parent = nullptr);
    ~Game();

private slots:
    void spawn();

private:
    std::shared_ptr<QGraphicsScene> scene_;
    std::unique_ptr<PlayerObject> player_;
    std::unique_ptr<QTimer> spawnObjectTimer_;
};
