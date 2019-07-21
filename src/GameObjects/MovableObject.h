#pragma once

#include "GameObject.h"

class AbstractVisitor;
class MoveStrategy;

/*!
 * \brief Родительский класс всех способных к движению объектов сцены (кроме PlayerObject).
 *
 * Реализует механизм движения игровых объектов на сцене.
 */
class MovableObject
        : public QObject
        , public GameObject
{
    Q_OBJECT

public:
    ///Деструктор по умолчанию.
    virtual ~MovableObject() override = default;
    ///Метод, принимающий объект посетителя.
    virtual void accept(AbstractVisitor &visitor) = 0;
    ///Метод перемещения объекта.
    virtual void move();
    ///Метод для установки скорости объекта.
    void setSpeed(unsigned int speed);
    ///Метод, возвращающий скорость объекта.
    unsigned int speed() const;
    ///Метод, возвращающий указатель на разделяемый объект стратегии движения.
    std::shared_ptr<MoveStrategy> moveStrategy() const;
protected:
    ///Конструктор с двумя аргументами.
    MovableObject(std::weak_ptr<QGraphicsScene> scene,
                  std::shared_ptr<MoveStrategy> moveStrategy);
private:
    std::shared_ptr<MoveStrategy> moveStrategy_;
};
