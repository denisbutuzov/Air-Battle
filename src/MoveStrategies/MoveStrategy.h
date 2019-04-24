#pragma once

class MovableObject;

class MoveStrategy
{
public:
    enum class DIRECTION
    {
        UP,
        DOWN
    };

    virtual ~MoveStrategy() = default;
    virtual void move(MovableObject &object) = 0;

    DIRECTION direction() const;

protected:
    MoveStrategy(DIRECTION dir);

private:
    DIRECTION dir_;
};
