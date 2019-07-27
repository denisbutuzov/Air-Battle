#pragma once

#include <QGraphicsTextItem>

#include <functional>
#include <memory>
#include <stack>

#include "SpecialObjects/Subjects/Equipment.h"
#include "AbstractObserver.h"

class QGraphicsScene;
class QGraphicsPixmapItem;

/*!
 * \ingroup Observers
 * \brief Класс наблюдателя за снаряжением игрока.
 *
 * Реализует виджет, наблюдающий за снаряжением игрока.
 */
class EquipmentObserver
        : public AbstractObserver
{
public:
    ///Конструктор с одним аргументом.
    EquipmentObserver(std::weak_ptr<Equipment> equipment);
    ///Метод для обновления представления.
    virtual void update() override;
    ///Метод для отображения наблюдателя.
    void show(std::weak_ptr<QGraphicsScene> scene, QPointF coordinate = QPointF(0.0, 0.0));
private:
    ///Метод для добавление патрона на представление наблюдателя.
    void addPatron();
    ///Метод для удаления патрона из представления наблюдателя.
    void removePatron();
    ///Метод для приведения представления в соответствии со значением наблюдаемого объекта.
    void repeatWhileSizesAreNotEqual(std::function<void()> &&callBack);
    ///Метод для установки названия вида оружия.
    void setText(Equipment::WeaponType weapon);
    ///Метод для удаления всех патронов с представления.
    void clearMagazine();
private:
    std::weak_ptr<Equipment> subject_;
    std::weak_ptr<QGraphicsScene> scene_;
    QPointF coordinate_;
    QGraphicsTextItem weaponType_;
    std::stack<std::unique_ptr<QGraphicsPixmapItem>> patrons_;
    Equipment::WeaponType currentWeaponType_;
};
