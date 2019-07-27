#include <QGraphicsScene>

#include "GameObjects/Bonuses/Detonation.h"

#include "AbstractLevelFactory.h"

constexpr const char *DETONATION_IMAGE = ":/images/images/Detonation.png";

/*!
 * \param scene Слабый указатель на объект сцены.
 */
AbstractLevelFactory::AbstractLevelFactory(std::weak_ptr<QGraphicsScene> scene)
    : scene_(scene)
{
}

/*!
 * \return Слабый указатель на объект сцены.
 */
std::weak_ptr<QGraphicsScene> AbstractLevelFactory::scene() const
{
    return scene_;
}

/*!
 * \param pixmap Путь до изображения порождаемого объекта.
 * \return Случайную позицию на верху игровой сцены.
 */
QPointF AbstractLevelFactory::randomPos(const QPixmap &pixmap)
{
    if(auto wp = scene_.lock())
    {
        int randomNumber = rand() % static_cast<int>(wp->width() - pixmap.width());
        return QPointF(randomNumber, 0 - pixmap.height());
    }
    return QPointF(0.0, 0.0);
}

/*!
 * \return Объект взрывающего бонуса.
 */
std::unique_ptr<Bonus> AbstractLevelFactory::bonus()
{
    auto bonus = std::make_unique<Detonation>(scene());
    bonus->setPixmap(QPixmap(DETONATION_IMAGE));
    bonus->setPos(randomPos(bonus->pixmap()));
    return bonus;
}
