#include "LevelFactories/Level1Factory.h"
#include "GameObjects/Enemies/Enemy.h"

#include "FactoryManager.h"

std::unique_ptr<MovableObject> FactoryManager::createSpawnObject(std::weak_ptr<QGraphicsScene> scene,
                                                                 std::weak_ptr<Level> level)
{
    return callFactory(std::make_unique<Level1Factory>(scene));
}

std::unique_ptr<MovableObject> FactoryManager::callFactory(std::unique_ptr<AbstractLevelFactory> &&factory)
{
    return factory->enemy();
}
