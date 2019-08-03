#pragma once
class Car
{
private:
	int velocity;
    int currentGear;
public:
    enum Gears {R = -1, N = 0};
    virtual ~Car() = default;
    void turnLeft();
    void turnRight();
    void brake();
    void checkAccelerate(int speed);
    void accelerateErr();
    void accelerate(int speed);
    void changeGear(int gear);
    virtual void feed()=0;
};

