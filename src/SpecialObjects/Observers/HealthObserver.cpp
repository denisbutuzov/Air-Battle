#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

#include "SpecialObjects/Subjects/Health.h"

#include "HealthObserver.h"

HealthObserver::HealthObserver(Health *health)
    : subject_(health)
{
    subject_->attach(this);
}

void HealthObserver::update()
{
    if(hearts_.size() < subject_->value())
    {
        repeatWhileSizesAreNotEqual(std::bind(&HealthObserver::addHeart, this));
    }
    else
    {
        repeatWhileSizesAreNotEqual(std::bind(&HealthObserver::removeHeart, this));
    }
}

void HealthObserver::show(std::shared_ptr<QGraphicsScene> &scene, QPointF coordinate)
{
    scene_ = scene;
    coordinate_ = coordinate;

    for (int i = 0; i != subject_->value(); ++i)
    {
        addHeart();
    }
}

void HealthObserver::addHeart()
{
    auto *heart = new QGraphicsPixmapItem(QPixmap(":/images/images/Heart.png").scaled(20, 20));
    if(!hearts_.empty())
    {
        heart->setPos(hearts_.back()->pos() + QPointF(hearts_.back()->pixmap().width() + 5.0, 0.0));
    }
    else
    {
        heart->setPos(coordinate_);
    }
    scene_->addItem(heart);
    hearts_.enqueue(heart);
}

void HealthObserver::removeHeart()
{
    auto *heart = hearts_.dequeue();
    delete heart;
}

void HealthObserver::repeatWhileSizesAreNotEqual(std::function<void ()> &&callBack)
{
    while(hearts_.size() != subject_->value())
    {
        callBack();
    }
}
