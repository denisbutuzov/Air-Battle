#include <unordered_map>

#include "LevelFactories/Level1Factory.h"
#include "LevelFactories/Level2Factory.h"
#include "LevelFactories/Level3Factory.h"
#include "LevelFactories/Level4Factory.h"
#include "LevelFactories/Level5Factory.h"
#include "SpecialObjects/Subjects/Level.h"
#include "GameObjects/Enemies/Enemy.h"
#include "GameObjects/Weapons/Weapon.h"
#include "GameObjects/Bonuses/Bonus.h"

#include "FactoryManager.h"

/*!
 * \param scene Слабый указатель на объект игровой сцены.
 * \param level Слабый указатель на объект уровня в игре.
 *
 * \return Способный к движению игровой объект.
 *
 * Реализует создание игрового объекта в зависимости от текущего уровня в игре.
 */
std::unique_ptr<MovableObject> FactoryManager::createSpawnObject(std::weak_ptr<QGraphicsScene> scene,
                                                                 std::weak_ptr<Level> level)
{
    const std::unordered_map<unsigned int, std::function<std::unique_ptr<AbstractLevelFactory>()>> FUNCTION_MAP
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

/*!
 * \param factory Конкретная игровая фабрика.
 *
 * \return Способный к движению игровой объект.
 *
 * Реализует механизм поочередного создания игровых объектов конкретной
 * игровой фабрикой, переданной в качестве аргумента.
 */
std::unique_ptr<MovableObject> FactoryManager::callFactory(std::unique_ptr<AbstractLevelFactory> &&factory)
{
    static unsigned int queue = 0;

    if(++queue <= 5)
    {
        return factory->enemy();
    }
    else if(queue == 6)
    {
        ++queue;
        return factory->weapon();
    }
    else
    {
        queue = 0;
        return factory->bonus();
    }
}
