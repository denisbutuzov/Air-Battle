#include "AbstractSubject.h"

void AbstractSubject::attach(std::shared_ptr<AbstractObserver> observer)
{
    observers_.push_back(observer);
}

void AbstractSubject::detach(std::shared_ptr<AbstractObserver> observer)
{
    observers_.remove(observer);
}

void AbstractSubject::notify()
{
//    for(auto *observer : observers_)
//    {
//        if (observer != nullptr)
//        {
//            observer->update();
//        }
//        else
//        {
//            observers_.remove(observer);
//        }
//    }
}
