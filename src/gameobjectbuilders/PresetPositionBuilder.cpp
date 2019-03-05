#include <QGraphicsScene>

#include "Enemy.h"
#include "PlayerObject.h"

#include "PresetPositionBuilder.h"

Enemy *PresetPositionBuilder::buildEnemy(const std::shared_ptr<QGraphicsScene> &scene, unsigned int speed,
                                         unsigned int hitpoint, const QString &pixmap, const QPointF &pos)
{
    auto *enemy = GameObjectBuilder::buildEnemy(scene, speed, hitpoint, pixmap, pos);
    int randomNumber = rand() % static_cast<int>(scene->width() - enemy->pixmap().width());
    enemy->setPos(randomNumber, 0 - enemy->pixmap().height());
    return enemy;
}

std::unique_ptr<PlayerObject> PresetPositionBuilder::buildPlayer(const std::shared_ptr<QGraphicsScene> &scene,
                                                                 const QString &pixmap, const QPointF &pos)
{
    auto player = GameObjectBuilder::buildPlayer(scene, pixmap, pos);
    player->setPos((scene->width() - player->pixmap().width())/2,
                    scene->height() - player->pixmap().height());
    return player;
}
