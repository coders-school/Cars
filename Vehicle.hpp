#pragma once
class Vehicle {
   public:
    Vehicle();
    virtual ~Vehicle();
    void turnLeft(){};
    void turnRight(){};
    void brake(){};
    void accelerate(int){};
    virtual void restore() = 0;
};
