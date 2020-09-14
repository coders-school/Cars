#pragma once
#include "Car.hpp"
#include "ElectricEngine.hpp"
#include <memory>

class ElectricCar : virtual public Car {
public:
  ElectricCar(std::unique_ptr<ElectricEngine> engine);
  ~ElectricCar();
  ElectricEngine *getElectricEngineData() const;
  std::unique_ptr<ElectricEngine> pullOutElectricEngine();
  void restore() override;
  void accelerate(int a) override;

private:
  std::unique_ptr<ElectricEngine> engine_;
  void charge();
};
