#pragma once

#include <memory>

class Level;
class MovableObject;
class AbstractLevelFactory;
class QGraphicsScene;

class Director
{
public:
    static std::unique_ptr<MovableObject> createSpawnObject(std::shared_ptr<QGraphicsScene> scene,
                                                            Level *level);
private:
    Director() = default;

    static std::unique_ptr<MovableObject> callFactory(std::unique_ptr<AbstractLevelFactory> &factory);
};
