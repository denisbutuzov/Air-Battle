#include "Score.h"

/*!
 * Инициализирует значение счета в игре нулем.
 */
Score::Score()
    : score_(0)
{
}

/*!
 * Увеличивает значение счета в игре на единицу и оповещает
 * всех наблюдателей.
 */
void Score::increase()
{
    ++score_;
    notify();
}

/*!
 * \return Значение счета в игре.
 */
unsigned int Score::value() const
{
    return score_;
}
