#include "HealthObserver.h"

HealthObserver::HealthObserver(Health *health)
    : subject_(health)
{
    subject_->attach(this);
}

void HealthObserver::update()
{
    if(static_cast<unsigned int>(hearts_.size()) < subject_->health())
    {
        repeatWhileSizesAreNotEqual(std::bind(&HealthObserver::addHeart, this));
    }
    else
    {
        repeatWhileSizesAreNotEqual(std::bind(&HealthObserver::removeHeart, this));
    }
}

void HealthObserver::show(QGraphicsScene *scene, QPointF coordinate)
{
    scene_ = scene;
    coordinate_ = coordinate;

    for (unsigned int i = 0; i != subject_->health(); ++i)
    {
        addHeart();
    }
}

QPointF HealthObserver::coordinate() const
{
    return coordinate_;
}

const QQueue<HeartObject *> &HealthObserver::hearts() const
{
    return hearts_;
}

void HealthObserver::addHeart()
{
    auto *heart = new HeartObject(scene_, this);
    heart->init();
    hearts_.enqueue(heart);
}

void HealthObserver::removeHeart()
{
    auto *heart = hearts_.dequeue();
    delete heart;
}

void HealthObserver::repeatWhileSizesAreNotEqual(std::function<void ()> &&callBack)
{
    while(static_cast<unsigned int>(hearts_.size()) != subject_->health())
    {
        callBack();
    }
}
