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
    void setSpeed(unsigned int speed);
    unsigned int speed() const;

protected:
    MoveStrategy(DIRECTION dir, unsigned int speed);

private:
    DIRECTION dir_;
    unsigned int speed_;
};
