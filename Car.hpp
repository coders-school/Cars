#pragma once

class Car
{
protected:
    int velocity = 0;
public:
    virtual ~Car() = default;
    void turnLeft();
    void turnRight();
    void brake(int speed);
    int get_speed() const;
    void set_speed(int speed);
    void accelerate(int speed);
    void feed();
};

