#pragma once

#include <QPointF>

#include "GameObjectBuilder.h"

class PresetPositionBuilder
        : GameObjectBuilder
{
public:
    PresetPositionBuilder() = default;
    virtual ~PresetPositionBuilder() override = default;
    virtual std::unique_ptr<Enemy> buildEnemy(const std::shared_ptr<QGraphicsScene> &scene, unsigned int speed,
                                              unsigned int hitpoint, const QString &pixmap,
                                              const QPointF &pos = QPointF(0.0, 0.0)) override final;
    virtual std::unique_ptr<PlayerObject> buildPlayer(const std::shared_ptr<QGraphicsScene> &scene, const QString &pixmap,
                                                      const QPointF &pos = QPointF(0.0, 0.0)) override final;
};
