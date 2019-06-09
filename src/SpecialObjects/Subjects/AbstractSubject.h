#pragma once

#include <list>
#include <memory>

class AbstractObserver;

class AbstractSubject
{
public:
    virtual ~AbstractSubject() = default;
    virtual void attach(std::shared_ptr<AbstractObserver> observer);
    virtual void detach(std::shared_ptr<AbstractObserver> observer);
    virtual void notify();
protected:
    AbstractSubject() = default;
private:
    std::list<std::shared_ptr<AbstractObserver>> observers_;
};
