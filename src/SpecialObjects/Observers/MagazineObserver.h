#pragma once

#include <QGraphicsTextItem>

#include <functional>
#include <memory>
#include <stack>

#include "SpecialObjects/Subjects/Magazine.h"
#include "AbstractObserver.h"

class QGraphicsScene;
class QGraphicsPixmapItem;

class MagazineObserver
        : public AbstractObserver
{
public:
    MagazineObserver(Magazine *health);
    virtual void update() override;

    void show(std::shared_ptr<QGraphicsScene> &scene, QPointF coordinate = QPointF(0.0, 0.0));

private:
    void addPatron();
    void removePatron();
    void repeatWhileSizesAreNotEqual(std::function<void()> &&callBack);
    void setText(Magazine::Weapon weapon);
    void clearMagazine();

private:
    Magazine *subject_;
    QPointF coordinate_;
    std::shared_ptr<QGraphicsScene> scene_;
    std::stack<QGraphicsPixmapItem *> patrons_;
    QGraphicsTextItem text_;
    Magazine::Weapon currentWeapontType_;
};
