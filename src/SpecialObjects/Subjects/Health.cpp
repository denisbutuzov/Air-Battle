#include "Health.h"

/*!
 * \param maxHealth Максимальное значение здоровья игрока.
 */
Health::Health(int maxHealth)
    : health_(maxHealth)
    , maxHealth_(maxHealth)
{
}

/*!
 * Увеличивает значение здоровья игрока на одну единицу и
 * оповещает всех наблюдателей.
 */
void Health::increase()
{
    if (health_ < maxHealth_)
    {
        ++health_;
        notify();
    }
}

/*!
 * Уменьшает здоровье игрока на одну единицу и оповещает
 * всех наблюдателей.
 */
void Health::decrease()
{
    if (health_ > 0)
    {
        --health_;
        notify();
    }
}

/*!
 * \return Значение текущего здоровья игрока.
 */
int Health::value() const
{
    return health_;
}
