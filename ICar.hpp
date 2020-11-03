#pragma once
#include <iostream>

#include "EngineParameters.hpp"

class ICar {
public:
  virtual ~ICar(){};
  virtual void turnLeft() const {
    std::cout << __FUNCTION__ << ": " << __FILE__ << ": " << __LINE__
              << std::endl;
  }
  virtual void turnRight() const {
    std::cout << __FUNCTION__ << ": " << __FILE__ << ": " << __LINE__
              << std::endl;
  }
  virtual void brake() const {
    std::cout << __FUNCTION__ << ": " << __FILE__ << ": " << __LINE__
              << std::endl;
  }
  virtual void accelerate(Speed speed) const {
    std::cout << __FUNCTION__ << ": " << __FILE__ << ": " << __LINE__
              << std::endl;
    std::cout << "Speed : " << speed.speed_ << std::endl;
  }
  virtual void start_engine() const {
    std::cout << __FUNCTION__ << ": " << __FILE__ << ": " << __LINE__
              << std::endl;
  }

  virtual void stop_engine() const {
    std::cout << __FUNCTION__ << ": " << __FILE__ << ": " << __LINE__
              << std::endl;
  }

  virtual void fill() {
    std::cout << __FUNCTION__ << ": " << __FILE__ << ": " << __LINE__
              << std::endl;
  }
};
