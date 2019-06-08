#include <unordered_map>

#include "LevelFactories/Level1Factory.h"
#include "LevelFactories/Level2Factory.h"
#include "LevelFactories/Level3Factory.h"
#include "LevelFactories/Level4Factory.h"
#include "LevelFactories/Level5Factory.h"
#include "SpecialObjects/Subjects/Level.h"
#include "GameObjects/Weapons/Weapon.h"
#include "GameObjects/Enemies/Enemy.h"

#include "Director.h"

std::unique_ptr<MovableObject> Director::createSpawnObject(std::shared_ptr<QGraphicsScene> scene, Level *level)
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
    auto it = FUNCTION_MAP.find(level->value());
    if(it != FUNCTION_MAP.end())
    {
        levelFactory = it->second();
    }
    else
    {
        levelFactory = std::make_unique<Level1Factory>(scene);
    }

    return callFactory(std::move(levelFactory));
}

std::unique_ptr<MovableObject> Director::callFactory(std::unique_ptr<AbstractLevelFactory> &&factory)
{
    int randomNumber = rand() % 10;
    if(randomNumber > 6)
    {
        return factory->weapon();
    }
    else
    {
        return factory->enemy();
    }
}
