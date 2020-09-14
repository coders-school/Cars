#pragma once
class Car {

public:
  ~Car();
  void turnLeft();
  void turnRight();
  void brake();
  virtual void accelerate(int speed);
  virtual void restore() = 0;
  int speed = 0;
};
