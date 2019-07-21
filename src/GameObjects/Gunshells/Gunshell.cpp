#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QTimer>

#include "Visitors/AbstractVisitor.h"

#include "Gunshell.h"

constexpr const char *GUNSHELL_BULLET_BOOM = "qrc:/sounds/sounds/Bullet_boom.wav";
constexpr const char *GUNSHELL_BOOM_IMAGE = ":/images/images/Gunshell_boom.png";

/*!
 * \param scene Слабый указатель на объект сцены.
 * \param damage Значение урона оружейного снаряда.
 * \param moveStrategy Указатель на разделяемый объект стратегии движения.
 */
Gunshell::Gunshell(std::weak_ptr<QGraphicsScene> scene,
                   int damage,
                   std::shared_ptr<MoveStrategy> moveStrategy)
    : MovableObject(scene, moveStrategy)
    , damage_(damage)
{
}

/*!
 * Уничтожает объект оружейного снаряда с воспроизведением звука попадания
 * оружейного снаряда во врага (Enemy) и прорисовкой небольшого взрыва на месте
 * попадания.
 */
Gunshell::~Gunshell()
{
    if(auto wp = scene().lock())
    {
        if(y() > 0)
        {
            QMediaPlayer *sound = new QMediaPlayer;
            sound->setMedia(QMediaContent(QUrl(GUNSHELL_BULLET_BOOM)));
            sound->play();
            QTimer::singleShot(std::chrono::seconds(2), [sound = sound](){ delete sound; });

            QGraphicsPixmapItem *pixmap = new QGraphicsPixmapItem(QPixmap(GUNSHELL_BOOM_IMAGE));
            pixmap->setPos(pos());
            wp->addItem(pixmap);
            QTimer::singleShot(std::chrono::milliseconds(100), [pixmap = pixmap](){ delete pixmap; });
        }
    }
}

/*!
 * \param visitor Объект посетителя.
 *
 * Вызывает метод `void visitGunshell(Gunshell *gunshell)` переданного в качестве параметра
 * объекта посетителя.
 */
void Gunshell::accept(AbstractVisitor &visitor)
{
    visitor.visitGunshell(this);
}

/*!
 * \param damage Значение урона оружейного снаряда.
 *
 * Устанавливает урон оружейному снаряду.
 */
void Gunshell::setDamage(int damage)
{
    damage_ = damage;
}

/*!
 * \return Значение урона оружейного снаряда.
 */
int Gunshell::damage() const
{
    return damage_;
}
