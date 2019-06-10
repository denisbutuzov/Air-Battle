#include <unordered_map>

#include "LevelFactories/Level1Factory.h"
#include "LevelFactories/Level2Factory.h"
#include "LevelFactories/Level3Factory.h"
#include "LevelFactories/Level4Factory.h"
#include "LevelFactories/Level5Factory.h"
#include "SpecialObjects/Subjects/Level.h"
#include "GameObjects/Enemies/Enemy.h"

#include "FactoryManager.h"

std::unique_ptr<MovableObject> FactoryManager::createSpawnObject(std::weak_ptr<QGraphicsScene> scene,
                                                                 std::weak_ptr<Level> level)
{
    static const std::unordered_map<unsigned int, std::function<std::unique_ptr<AbstractLevelFactory>()>> FUNCTION_MAP
    {
        { 1, [scene](){ return std::make_unique<Level1Factory>(scene); } },
        { 2, [scene](){ return std::make_unique<Level2Factory>(scene); } },
        { 3, [scene](){ return std::make_unique<Level3Factory>(scene); } },
        { 4, [scene](){ return std::make_unique<Level4Factory>(scene); } },
        { 5, [scene](){ return std::make_unique<Level5Factory>(scene); } }
    };

    std::unique_ptr<AbstractLevelFactory> levelFactory;
    if(auto wp = level.lock())
    {
        auto it = FUNCTION_MAP.find(wp->value());
        if(it != FUNCTION_MAP.end())
        {
            levelFactory = it->second();
            return callFactory(std::move(levelFactory));
        }
    }
    levelFactory = std::make_unique<Level1Factory>(scene);
    return callFactory(std::move(levelFactory));
}

std::unique_ptr<MovableObject> FactoryManager::callFactory(std::unique_ptr<AbstractLevelFactory> &&factory)
{
    return factory->enemy();
}
