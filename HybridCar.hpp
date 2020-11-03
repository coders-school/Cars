#pragma once

#include "ElectricEngine.hpp"
#include "ICar.hpp"
#include "PetrolEngine.hpp"
#include <memory>

class HybridCar : public ICar {
public:
  HybridCar(std::unique_ptr<IEngine> petrolEng,
            std::unique_ptr<IEngine> electricEng);
  ~HybridCar();
  void start_engine() const override;
  void stop_engine() const override;
  void fill() override;
  void charge();
  void refuel();

private:
  std::unique_ptr<IEngine> petrolEngine_ = nullptr;
  std::unique_ptr<IEngine> electricEngine_ = nullptr;
};
