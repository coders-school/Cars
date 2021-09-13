#pragma once

class Car {
   public:
    void turnLeft();
    void turnRight();
    void brake();
    void accelerate(int speed);

    virtual void restore() = 0;
    virtual ~Car() {}

   private:
    int speed_{0};
};
