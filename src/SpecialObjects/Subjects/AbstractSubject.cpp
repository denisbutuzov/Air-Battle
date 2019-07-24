#include "SpecialObjects/Observers/AbstractObserver.h"

#include "AbstractSubject.h"

/*!
 * \param observer Прикрепляемый наблюдатель.
 *
 * Добавляет переданного наблюдателя в список наблюдателей, отслеживающих
 * состояние данного субъекта.
 */
void AbstractSubject::attach(AbstractObserver *observer)
{
    observers_.push_back(observer);
}

/*!
 * \param observer Отвязываемый наблюдатель.
 *
 * Исключает переданного наблюдателя из списка наблюдателей, отслеживающих
 * состояние данного субъекта.
 */
void AbstractSubject::detach(AbstractObserver *observer)
{
    observers_.remove(observer);
}

/*!
 * Оповещает всех наблюдателей об изменении, произошедшем в состоянии
 * данного субъекта.
 */
void AbstractSubject::notify()
{
    for(auto *observer : observers_)
    {
        if (observer != nullptr)
        {
            observer->update();
        }
        else
        {
            observers_.remove(observer);
        }
    }
}
