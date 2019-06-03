#include <QGraphicsScene>

#include "AbstractLevelFactory.h"

AbstractLevelFactory::AbstractLevelFactory(std::shared_ptr<QGraphicsScene> scene)
    : scene_(scene)
{
}

std::shared_ptr<QGraphicsScene> AbstractLevelFactory::scene()
{
    return scene_;
}

QPointF AbstractLevelFactory::randomPos(const QPixmap &pixmap)
{
    int randomNumber = rand() % static_cast<int>(scene()->width() - pixmap.width());
    return QPointF(randomNumber, 0 - pixmap.height());
}
