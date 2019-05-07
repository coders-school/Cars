#pragma once

class Engine;

class Car {
public:
    virtual ~Car() {}
    void turnLeft();
    void turnRight();
    void brake();
    void accelerate(int speed);
    virtual void feed() = 0;
    virtual void setEngine(Engine* e) = 0;
};
