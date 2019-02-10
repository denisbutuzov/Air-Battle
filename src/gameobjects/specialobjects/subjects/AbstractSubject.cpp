#include "AbstractObserver.h"

#include "AbstractSubject.h"

void AbstractSubject::attach(AbstractObserver *observer)
{
    observers_.push_back(observer);
}

void AbstractSubject::detach(AbstractObserver *observer)
{
    observers_.remove(observer);
}

void AbstractSubject::notify()
{
    for(auto *observer : observers_)
    {
        observer->update();
    }
}
