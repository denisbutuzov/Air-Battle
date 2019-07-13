#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QTimer>

#include "Visitors/AbstractVisitor.h"

#include "Enemy.h"

constexpr const char *EXPLOSION_SOUND = "qrc:/sounds/sounds/explosion.wav";
constexpr const char *EXPLOSION_IMAGE = ":/images/images/Enemy_boom.png";

Enemy::Enemy(std::weak_ptr<QGraphicsScene> scene,
             int hitpoint,
             std::shared_ptr<MoveStrategy> moveStrategy)
    : MovableObject(scene, moveStrategy)
    , hitpoint_(hitpoint)
{
}

Enemy::~Enemy()
{
    if(auto wp = scene().lock())
    {
        if(pos().y() < wp->sceneRect().height())
        {
            QMediaPlayer *sound = new QMediaPlayer;
            sound->setMedia(QMediaContent(QUrl(EXPLOSION_SOUND)));
            sound->setVolume(40);
            sound->play();

            QGraphicsPixmapItem *pixmap = new QGraphicsPixmapItem(QPixmap(EXPLOSION_IMAGE));
            pixmap->setPos(pos());
            wp->addItem(pixmap);

            QTimer::singleShot(std::chrono::seconds(2), [sound = sound](){ delete sound; });
            QTimer::singleShot(std::chrono::milliseconds(150), [pixmap = pixmap](){ delete pixmap; });
        }
    }
}

void Enemy::accept(AbstractVisitor &visitor)
{
    visitor.visitEnemy(this);
}

void Enemy::setHitpoint(int hitpoint)
{
    hitpoint_ = hitpoint;
}

int Enemy::hitpoint() const
{
    return hitpoint_;
}
