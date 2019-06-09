#pragma once

#include <memory>

class Level;
class MovableObject;
class AbstractLevelFactory;
class QGraphicsScene;

class FactoryManager
{
public:
    static std::unique_ptr<MovableObject> createSpawnObject(std::weak_ptr<QGraphicsScene> scene,
                                                            std::weak_ptr<Level> level);
private:
    FactoryManager() = default;
    static std::unique_ptr<MovableObject> callFactory(std::unique_ptr<AbstractLevelFactory> &&factory);
};
