#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

#include "SpecialObjects/Subjects/Health.h"

#include "HealthObserver.h"

HealthObserver::HealthObserver(std::weak_ptr<Health> health, const QString &pixmap)
    : subject_(health)
    , pixmap_(pixmap)
{
    if(auto wp = subject_.lock())
    {
        wp->attach(this);
    }
}

void HealthObserver::update()
{
    if(auto wp = subject_.lock())
    {
        auto tempVal = wp->value();
        if(static_cast<int>(hearts_.size()) < tempVal)
        {
            repeatWhileSizesAreNotEqual(std::bind(&HealthObserver::addHeart, this), tempVal);
        }
        else
        {
            repeatWhileSizesAreNotEqual(std::bind(&HealthObserver::removeHeart, this), tempVal);
        }
    }
}

void HealthObserver::show(std::weak_ptr<QGraphicsScene> scene, QPointF coordinate)
{
    scene_ = scene;
    coordinate_ = coordinate;

    if(!scene_.expired() && !subject_.expired())
    {
        auto tempVal = subject_.lock()->value();
        for (int i = 0; i != tempVal; ++i)
        {
            addHeart();
        }
    }
}

void HealthObserver::addHeart()
{
    auto heart = std::make_unique<QGraphicsPixmapItem>(pixmap_);
    if(!hearts_.empty())
    {
        heart->setPos(hearts_.back()->pos() + QPointF(hearts_.back()->pixmap().width() + 5.0, 0.0));
    }
    else
    {
        heart->setPos(coordinate_);
    }
    scene_.lock()->addItem(heart.get());
    hearts_.push(std::move(heart));
}

void HealthObserver::removeHeart()
{
    hearts_.pop();
}

void HealthObserver::repeatWhileSizesAreNotEqual(std::function<void ()> &&callBack, int value)
{
    while(static_cast<int>(hearts_.size()) != value)
    {
        callBack();
    }
}
