#include <QGraphicsScene>

#include "AbstractLevelFactory.h"

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
