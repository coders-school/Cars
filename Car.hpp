#pragma once

class Car
{
  public:
    Car(int maxSpeed, int maxReverseSpeed);

    virtual ~Car() = default;
    void turnLeft();
    void turnRight();
    void brake(int desiredSpeed = 0);
    void accelerate(int speedChange);
    virtual void refill() = 0;
    int currentSpeed() const;

  protected:
    void startMoving(int speedChange);
    void changeForwardSpeed(int speedChange);
    void changeReverseSpeed(int speedChange);
    const int maxSpeed_;
    const int maxReverseSpeed_;
    int currentSpeed_ = 0;
};
