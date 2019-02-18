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

    virtual ~MoveStrategy();
    virtual void move(qreal &x, qreal &y, qreal speed) = 0;

protected:
    MoveStrategy(DIRECTION dir);

    DIRECTION direction() const;

private:
    DIRECTION dir_;
};
