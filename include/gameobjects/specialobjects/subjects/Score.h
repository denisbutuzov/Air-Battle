#pragma once

#include <cstdint>

#include "AbstractSubject.h"

class Score
        : public AbstractSubject
{
public:
    static Score *instance();
    void increase();
    uint16_t score() const;

protected:
    Score();
    Score(const Score &other) = delete;
    Score(Score &&other) = delete;

    Score &operator=(const Score &other) = delete;
    Score &operator=(Score &&other) = delete;

private:
    static Score *instance_;
    uint16_t score_;
};
