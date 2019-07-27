#pragma once

#include <memory>

class Level;
class MovableObject;
class AbstractLevelFactory;
class QGraphicsScene;

/*!
 * \brief Класс-менеджер игровых фабрик.
 *
 * Инкапсулирует создание игровых объектов конкретной игровой фабрикой в зависимости
 * от текущего уровня в игре.
 */
class FactoryManager
{
public:
    ///Статический метод, возвращающий игровой объект.
    static std::unique_ptr<MovableObject> createSpawnObject(std::weak_ptr<QGraphicsScene> scene,
                                                            std::weak_ptr<Level> level);
private:
    ///Конструктор по умолчанию.
    FactoryManager() = default;
    ///Статический метод, обращающийся к конкретной фабрике с целью создания игрового объекта.
    static std::unique_ptr<MovableObject> callFactory(std::unique_ptr<AbstractLevelFactory> &&factory);
};
