#pragma once

#include <list>

class AbstractObserver;

class AbstractSubject
{
public:
    virtual ~AbstractSubject() = default;
    virtual void attach(AbstractObserver *observer);
    virtual void detach(AbstractObserver *observer);
    virtual void notify();

protected:
    AbstractSubject() = default;

private:
    std::list<AbstractObserver *> observers_;
};
