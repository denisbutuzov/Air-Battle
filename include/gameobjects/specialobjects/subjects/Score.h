#pragma once

#include "AbstractSubject.h"

class Score
        : public AbstractSubject
{
public:
    static Score *instance();
    void increase();
    unsigned int score() const;

protected:
    Score();
    Score(const Score &other) = delete;
    Score(Score &&other) = delete;

    Score &operator=(const Score &other) = delete;
    Score &operator=(Score &&other) = delete;

private:
    static Score *instance_;
    unsigned int score_;
};
