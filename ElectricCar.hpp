#pragma once

#include "ElectricEngine.hpp"
#include "ICar.hpp"
#include <memory>

class ElectricCar : public ICar {
public:
  ElectricCar(std::unique_ptr<IEngine> engine);
  ~ElectricCar();
  void start_engine() const override;
  void stop_engine() const override;
  void fill() override;
  void charge();

private:
  std::unique_ptr<IEngine> engine_ = nullptr;
};
