#include <QGraphicsScene>

#include "SpecialObjects/Subjects/Magazine.h"

#include "MagazineObserver.h"

MagazineObserver::MagazineObserver(Magazine *health)
    : subject_(health)
{
    subject_->attach(this);
}

void MagazineObserver::update()
{
    if(static_cast<int>(patrons_.size()) < subject_->value())
    {
        repeatWhileSizesAreNotEqual(std::bind(&MagazineObserver::addPatron, this));
    }
    else
    {
        repeatWhileSizesAreNotEqual(std::bind(&MagazineObserver::removePatron, this));
    }
}

void MagazineObserver::show(std::shared_ptr<QGraphicsScene> &scene, QPointF coordinate)
{
    scene_ = scene;
    coordinate_ = coordinate;

    for (int i = 0; i != subject_->value(); ++i)
    {
        addPatron();
    }
}

void MagazineObserver::addPatron()
{
    auto *patron = new QGraphicsPixmapItem(QPixmap(":/images/images/Heart.png").scaled(20, 20));
    if(!patrons_.empty())
    {
        patron->setPos(patrons_.top()->pos() + QPointF(0.0, -(patrons_.top()->pixmap().height() + 1.0)));
    }
    else
    {
        patron->setPos(coordinate_);
    }
    scene_->addItem(patron);
    patrons_.push(patron);
}

void MagazineObserver::removePatron()
{
    auto *patron = patrons_.top();
    patrons_.pop();
    delete patron;
}

void MagazineObserver::repeatWhileSizesAreNotEqual(std::function<void ()> &&callBack)
{
    while(static_cast<int>(patrons_.size()) != subject_->value())
    {
        callBack();
    }
}
