#pragma once

#include <memory>

class Enemy;
class PlayerObject;
class QGraphicsScene;
class QString;
class QPointF;

class GameObjectBuilder
{
public:
    virtual ~GameObjectBuilder() = default;
    virtual Enemy *buildEnemy(const std::shared_ptr<QGraphicsScene> &scene, unsigned int speed,
                              unsigned int hitpoint, const QString &pixmap, const QPointF &pos) = 0;
    virtual PlayerObject *buildPlayer(const std::shared_ptr<QGraphicsScene> &scene, const QString &pixmap, const QPointF &pos) = 0;

protected:
    GameObjectBuilder() = default;
};
