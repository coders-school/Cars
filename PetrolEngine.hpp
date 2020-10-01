#pragma once

#include "EngineParameters.hpp"
#include "IEngine.hpp"

class PetrolEngine : public IEngine {
public:
  PetrolEngine(Power power, Capacity capacity, Gears gears);
  ~PetrolEngine();
  void changeGear(int gear);

  void start() const override;
  void stop() const override;

private:
  Power power_;       // in HP
  Capacity capacity_; // in ccm
  Gears gears_;
  int currentGear_;
};
