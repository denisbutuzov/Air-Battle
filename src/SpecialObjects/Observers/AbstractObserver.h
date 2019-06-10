#pragma once

class AbstractObserver
{
public:
    virtual ~AbstractObserver() = default;
    virtual void update() = 0;
protected:
    AbstractObserver() = default;
};
