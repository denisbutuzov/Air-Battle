#pragma once

#include <QGraphicsPixmapItem>

#include <memory>

/*!
 * \brief Родительский класс всех игровых объектов сцены.
 *
 * Реализует механизм инициализации объекта на игровой сцене
 * путем его добавления на сцену.
 */
class GameObject
        : public QGraphicsPixmapItem
{
public:
    ///Деструктор по умолчанию.
    virtual ~GameObject() = default;
    ///Метод инициализации объекта на сцене.
    virtual void init();
    ///Метод, возвращающий слабый указатель на объект сцены.
    std::weak_ptr<QGraphicsScene> scene() const;
protected:
    ///Конструктор с одним аргументом.
    GameObject(std::weak_ptr<QGraphicsScene> scene);
private:
    std::weak_ptr<QGraphicsScene> scene_;
};
