#include "Level.h"

/*!
 * \param maxLevel Значение максимального уровня в игре.
 */
Level::Level(unsigned int maxLevel)
    : level_(1)
    , maxLevel_(maxLevel)
{
}

/*!
 * \return Значение текущего уровня в игре.
 */
unsigned int Level::value() const
{
    return level_;
}

/*!
 * Реализует переход на следующий уровень в игре и
 * оповещает всех наблюдателей.
 */
void Level::increase()
{
    if(level_ < maxLevel_)
    {
        ++level_;
        notify();
    }
}
