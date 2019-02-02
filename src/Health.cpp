#include "Health.h"

Health *Health::instance_ = nullptr;

Health::Health()
    : maxHeartsNumber_(MAX_HEARTS_NUMBER)
{
}

Health *Health::instance()
{
    if(instance_ == nullptr)
    {
        instance_ = new Health();
    }
    return instance_;
}

void Health::show(QGraphicsScene *scene, QPointF coordinate)
{
    scene_ = scene;
    coordinate_ = coordinate;

    for (int i = 0; i < maxHeartsNumber_; i++)
    {
        addHeart();
    }
}

void Health::increase()
{
    if(hearts_.size() != maxHeartsNumber_)
    {
        addHeart();
    }
}

void Health::decrease()
{
    if(hearts_.size() != 0)
    {
        auto *heart = hearts_.dequeue();
        delete heart;
    }
}

QPointF Health::coordinate() const
{
    return coordinate_;
}

void Health::addHeart()
{
    auto *heart = new HeartObject(scene_, this);
    heart->init();
    hearts_.enqueue(heart);
}

const QQueue<HeartObject *> &Health::hearts() const
{
    return hearts_;
}
