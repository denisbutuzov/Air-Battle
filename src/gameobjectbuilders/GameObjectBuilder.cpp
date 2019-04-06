#include "Enemy.h"
#include "PlayerObject.h"
#include "HandWeapon.h"

#include "GameObjectBuilder.h"

std::unique_ptr<Enemy> GameObjectBuilder::buildEnemy(const std::shared_ptr<QGraphicsScene> &scene, unsigned int speed,
                                                     unsigned int hitpoint, const QString &pixmap, const QPointF &pos)
{
    auto enemy = std::make_unique<Enemy>(scene);
    enemy->setPixmap(QPixmap(pixmap));
    enemy->setSpeed(speed);
    enemy->setHitpoint(hitpoint);
    return enemy;
}

std::unique_ptr<PlayerObject> GameObjectBuilder::buildPlayer(const std::shared_ptr<QGraphicsScene> &scene,
                                                             const QString &pixmap, const QPointF &pos)
{
    auto player = std::make_unique<PlayerObject>(scene, std::make_unique<HandWeapon>(scene));
    player->setPixmap(QPixmap(pixmap));
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    return player;
}
