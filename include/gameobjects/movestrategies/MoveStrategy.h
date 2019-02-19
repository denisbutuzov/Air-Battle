#pragma once

#include <QtGlobal>

class MoveStrategy
{
public:
    enum class DIRECTION
    {
        UP,
        DOWN
    };

    virtual ~MoveStrategy() = default;
    virtual void move(qreal &x, qreal &y, qreal speed) = 0;

    DIRECTION direction() const;

protected:
    MoveStrategy(DIRECTION dir);

private:
    DIRECTION dir_;
};
