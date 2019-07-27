#pragma once

#include <QPointF>
#include <QString>

#include <functional>
#include <memory>
#include <queue>

#include "AbstractObserver.h"

class Health;
class QGraphicsScene;
class QGraphicsPixmapItem;

/*!
 * \ingroup Observers
 * \brief Класс наблюдателя за здоровьем игрока.
 *
 * Реализует виджет, наблюдающий за значением здоровья игрока.
 */
class HealthObserver
        : public AbstractObserver
{
public:
    ///Конструктор с двумя аргументами.
    HealthObserver(std::weak_ptr<Health> health, const QString &pixmap);\
    ///Метод для обновления представления.
    virtual void update() override;
    ///Метод для отображения наблюдателя.
    void show(std::weak_ptr<QGraphicsScene> scene, QPointF coordinate = QPointF(0.0, 0.0));
private:
    ///Метод для добавления единицы здоровья на представление наблюдателя.
    void addHeart();
    ///Метод для удаления единицы здоровья из представления наблюдателя.
    void removeHeart();
    ///Метод для приведения представления в соответствие со значением наблюдаемого объекта.
    void repeatWhileSizesAreNotEqual(std::function<void()> &&callBack, int value);
private:
    std::weak_ptr<Health> subject_;
    QPointF coordinate_;
    std::weak_ptr<QGraphicsScene> scene_;
    std::queue<std::unique_ptr<QGraphicsPixmapItem>> hearts_;
    QString pixmap_;
};
