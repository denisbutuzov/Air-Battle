#pragma once

#include <QGraphicsTextItem>

#include <functional>
#include <memory>
#include <stack>

#include "SpecialObjects/Subjects/Equipment.h"
#include "AbstractObserver.h"

class QGraphicsScene;
class QGraphicsPixmapItem;

class EquipmentObserver
        : public AbstractObserver
{
public:
    EquipmentObserver(std::weak_ptr<Equipment> equipment);
    virtual void update() override;
    void show(std::weak_ptr<QGraphicsScene> scene, QPointF coordinate = QPointF(0.0, 0.0));
private:
    void addPatron();
    void removePatron();
    void repeatWhileSizesAreNotEqual(std::function<void()> &&callBack);
    void setText(Equipment::Weapon weapon);
    void clearMagazine();
private:
    std::weak_ptr<Equipment> subject_;
    QPointF coordinate_;
    std::weak_ptr<QGraphicsScene> scene_;
    std::stack<std::unique_ptr<QGraphicsPixmapItem>> patrons_;
    QGraphicsTextItem text_;
    Equipment::Weapon currentWeapontType_;
};
