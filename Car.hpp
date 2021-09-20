#pragma once

class Car {
public:
    Car() = default;
    virtual ~Car() = default;

    void turnLeft();
    void turnRight();
    void brake();
    void accelerate(int speed);
};
