#pragma  once

class Car
{
public:
    virtual ~Car() = default;

    void turnLeft();
    void turnRight();
    void brake();
    void accelerate(int speed);
    int getSpeed();

    virtual void restore() = 0;

protected:
    int speed_{};
};
