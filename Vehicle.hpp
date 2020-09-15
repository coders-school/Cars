#pragma once
class Vehicle {
   public:
    Vehicle();
    virtual ~Vehicle();
    void turnLeft(){};
    void turnRight(){};
    void brake(){};
    void accelerateTo(size_t){};
    virtual void restore() = 0;
};
