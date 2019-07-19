#include <QGraphicsScene>

#include "GameObjects/Bonuses/Detonation.h"

#include "AbstractLevelFactory.h"

constexpr const char *DETONATION_IMAGE = ":/images/images/Detonation.png";

AbstractLevelFactory::AbstractLevelFactory(std::weak_ptr<QGraphicsScene> scene)
    : scene_(scene)
{
}

std::weak_ptr<QGraphicsScene> AbstractLevelFactory::scene() const
{
    return scene_;
}

QPointF AbstractLevelFactory::randomPos(const QPixmap &pixmap)
{
    if(auto wp = scene_.lock())
    {
        int randomNumber = rand() % static_cast<int>(wp->width() - pixmap.width());
        return QPointF(randomNumber, 0 - pixmap.height());
    }
    return QPointF(0.0, 0.0);
}

std::unique_ptr<Bonus> AbstractLevelFactory::bonus()
{
    auto bonus = std::make_unique<Detonation>(scene());
    bonus->setPixmap(QPixmap(DETONATION_IMAGE));
    bonus->setPos(randomPos(bonus->pixmap()));
    return bonus;
}
