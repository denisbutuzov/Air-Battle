#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QTimer>

#include "Visitors/AbstractVisitor.h"

#include "Enemy.h"

constexpr const char *EXPLOSION_SOUND = "qrc:/sounds/sounds/explosion.wav";
constexpr const char *EXPLOSION_IMAGE = ":/images/images/Enemy_boom.png";

/*!
 * \param scene Слабый указатель на объект сцены.
 * \param hitpoint Значение здоровья врага.
 * \param moveStrategy Указатель на разделяемый объект стратегии движения.
 */
Enemy::Enemy(std::weak_ptr<QGraphicsScene> scene,
             int hitpoint,
             std::shared_ptr<MoveStrategy> moveStrategy)
    : MovableObject(scene, moveStrategy)
    , hitpoint_(hitpoint)
    , type_(EnemyType::Enemy)
{
}

/*!
 * Уничтожает объект врага с воспроизведением звука уничтожения и
 * и прорисовкой взрыва на месте уничтожения.
 *
 * \note Только для типа врага "Враг"
 */
Enemy::~Enemy()
{
    if(auto wp = scene().lock())
    {
        if(pos().y() < wp->sceneRect().height())
        {
            if(enemyType() == EnemyType::Enemy)
            {
                QMediaPlayer *sound = new QMediaPlayer;
                sound->setMedia(QMediaContent(QUrl(EXPLOSION_SOUND)));
                sound->setVolume(40);
                sound->play();
                QTimer::singleShot(std::chrono::seconds(2), [sound = sound](){ delete sound; });

                QGraphicsPixmapItem *pixmap = new QGraphicsPixmapItem(QPixmap(EXPLOSION_IMAGE));
                pixmap->setPos(pos());
                wp->addItem(pixmap);
                QTimer::singleShot(std::chrono::milliseconds(150), [pixmap = pixmap](){ delete pixmap; });
            }
        }
    }
}

/*!
 * \param visitor Объект посетителя.
 *
 * Вызывает метод `void visitEnemy(Enemy *enemy)` переданного в качестве параметра
 * объекта посетителя.
 */
void Enemy::accept(AbstractVisitor &visitor)
{
    visitor.visitEnemy(this);
}

/*!
 * \param hitpoint Значение здоровья врага.
 *
 * Устанавливает здоровье врагу.
 */
void Enemy::setHitpoint(int hitpoint)
{
    hitpoint_ = hitpoint;
}

/*!
 * \return Значение текущего здоровья врага.
 */
int Enemy::hitpoint() const
{
    return hitpoint_;
}

/*!
 * \param type Тип объекта врага.
 *
 * Устанавливает тип объекта для врага.
 */
void Enemy::setEnemyType(Enemy::EnemyType type)
{
    type_ = type;
}

/*!
 * \return Тип объекта врага.
 */
Enemy::EnemyType Enemy::enemyType() const
{
    return type_;
}
