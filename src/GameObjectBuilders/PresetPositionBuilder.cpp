#include <QGraphicsScene>

#include "GameObjects/Enemies/Enemy.h"
#include "GameObjects/Gunshells/Gunshell.h"
#include "GameObjects/PlayerObject.h"

#include "PresetPositionBuilder.h"

std::unique_ptr<Enemy> PresetPositionBuilder::buildEnemy(const std::shared_ptr<QGraphicsScene> &scene, unsigned int speed,
                                                         unsigned int hitpoint, const QString &pixmap, const QPointF &pos)
{
    auto enemy = GameObjectBuilder::buildEnemy(scene, speed, hitpoint, pixmap, pos);
    int randomNumber = rand() % static_cast<int>(scene->width() - enemy->pixmap().width());
    enemy->setPos(randomNumber, 0 - enemy->pixmap().height());
    return enemy;
}

std::unique_ptr<Gunshell> PresetPositionBuilder::buildGunshell(const std::shared_ptr<QGraphicsScene> &scene, unsigned int speed,
                                                               unsigned int damage, const QString &pixmap, const QPointF &pos)
{
    auto gunshell = GameObjectBuilder::buildGunshell(scene, speed, damage, pixmap, pos);
    gunshell->setPos(pos);
    return gunshell;
}

std::unique_ptr<PlayerObject> PresetPositionBuilder::buildPlayer(const std::shared_ptr<QGraphicsScene> &scene,
                                                                 const QString &pixmap, const QPointF &pos)
{
    auto player = GameObjectBuilder::buildPlayer(scene, pixmap, pos);
    player->setPos((scene->width() - player->pixmap().width())/2,
                    scene->height() - player->pixmap().height());
    return player;
}
