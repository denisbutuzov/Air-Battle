#pragma once

#include <QGraphicsView>

#include <memory>

class PlayerObject;

class Game
        : public QGraphicsView
{
    Q_OBJECT

public:
    Game();
    ~Game();
private:
    std::shared_ptr<QGraphicsScene> scene_;
    std::unique_ptr<PlayerObject> player_;
};
