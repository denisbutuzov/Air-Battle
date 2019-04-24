#include "HealthObserver.h"

#include "HeartObject.h"

HeartObject::HeartObject(QGraphicsScene *scene, HealthObserver *parent)
    : GameObject(scene)
    , parent_(parent)
{
}

QPointF HeartObject::coordinate() const
{
    return pos();
}

void HeartObject::setObjectImage()
{
    setPixmap(QPixmap(":/images/images/Heart.png").scaled(WIDTH_SCALE_HEARTOBJECT, HEIGHT_SCALE_HEARTOBJECT));
}

void HeartObject::setStartObjectPos()
{
    if(parent_->hearts().size() == 0)
    {
        setPos(parent_->coordinate());
    }
    else
    {
        auto *backHeart = parent_->hearts().back();
        setPos(backHeart->coordinate() + QPointF(backHeart->pixmap().width() + WIDTH_BETWEEN_HEARTOBJECTS, 0));
    }
}