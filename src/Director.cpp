#include "LevelFactories/Level1Factory.h"
#include "LevelFactories/Level2Factory.h"
#include "LevelFactories/Level3Factory.h"
#include "SpecialObjects/Subjects/Level.h"
#include "GameObjects/Weapons/Weapon.h"
#include "GameObjects/Enemies/Enemy.h"

#include "Director.h"

std::unique_ptr<MovableObject> Director::createSpawnObject(std::shared_ptr<QGraphicsScene> scene, Level *level)
{
    std::unique_ptr<AbstractLevelFactory> levelFactory;
    if(level->value() == 1)
    {
        levelFactory = std::make_unique<Level1Factory>(scene);
    }
    else if(level->value() == 2)
    {
        levelFactory = std::make_unique<Level2Factory>(scene);
    }
    else
    {
        levelFactory = std::make_unique<Level3Factory>(scene);
    }

    return callFactory(levelFactory);
}

std::unique_ptr<MovableObject> Director::callFactory(std::unique_ptr<AbstractLevelFactory> &factory)
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
