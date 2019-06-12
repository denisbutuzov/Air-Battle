#pragma once

#include "AbstractSubject.h"

class Score
        : public AbstractSubject
{
public:
    explicit Score();
    void increase();
    unsigned int value() const;
private:
    unsigned int score_;
};
