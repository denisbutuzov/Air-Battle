#pragma once

class qreal;

class MoveStrategy
{
public:
    virtual ~MoveStrategy();
    virtual void move(qreal &x, qreal &y) = 0;

protected:
    MoveStrategy() = default;
};
