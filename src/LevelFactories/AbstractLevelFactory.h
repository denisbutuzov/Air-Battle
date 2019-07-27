#pragma once

#include <memory>

class QGraphicsScene;
class Enemy;
class Bonus;
class Weapon;
class QPointF;
class QPixmap;

/*!
 * \defgroup Level_factories Фабрики игровых объектов
 * \brief Данный модуль описывает фабрики, порождающие игровые объекты
 * в зависимости от уровня.
 */

/*!
 * \ingroup Level_factories
 * \brief Абстрактный родительский класс всех фабрик,
 * порождающих игровые объекты.
 *
 * Реализует интерфейс для порождения игровых объектов
 * конкретного игрового уровня.
 *
 * \todo Отказаться от иерархии данных классов. Инкапсулировать
 * порождение игровых объектов в класс FactoryManager.
 */
class AbstractLevelFactory
{
public:
    ///Деструктор по умолчанию.
    virtual ~AbstractLevelFactory() = default;
    ///Метод, возвращающий объект врага.
    virtual std::unique_ptr<Enemy> enemy() = 0;
    ///Метод, возвращаюий объект оружия.
    virtual std::unique_ptr<Weapon> weapon() = 0;
    ///Метод, возвращаюий объект бонуса.
    virtual std::unique_ptr<Bonus> bonus();
protected:
    ///Конструктор с одним аргументом.
    AbstractLevelFactory(std::weak_ptr<QGraphicsScene> scene);
    ///Метод, возвращающий слабый указатель на объект сцены.
    std::weak_ptr<QGraphicsScene> scene() const;
    ///Метод, возвращающий случайную позицию для создаваемого объекта.
    QPointF randomPos(const QPixmap &pixmap);
private:
    std::weak_ptr<QGraphicsScene> scene_;
};
