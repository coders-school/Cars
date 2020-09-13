#pragma once
#include "Car.hpp"
#include "ElectricEngine.hpp"
#include <memory>

class ElectricCar : virtual public Car {
public:
  ElectricCar(std::unique_ptr<ElectricEngine> engine);
  ~ElectricCar();
  void charge();
  ElectricEngine *getElectricEngineData() const;
  std::unique_ptr<ElectricEngine> pullOutElectricEngine();

private:
  std::unique_ptr<ElectricEngine> engine_;
};
