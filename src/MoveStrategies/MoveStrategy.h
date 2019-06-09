#pragma once

class MovableObject;

class MoveStrategy
{
public:
    enum class Direction
    {
        Up,
        Down
    };

public:
    virtual ~MoveStrategy() = default;
    virtual void move(MovableObject &object) = 0;
    Direction direction() const;
    void setSpeed(unsigned int speed);
    unsigned int speed() const;
protected:
    MoveStrategy(Direction dir, unsigned int speed);
private:
    Direction dir_;
    unsigned int speed_;
};
