#pragma once

#include "EngineParameters.hpp"
#include "IEngine.hpp"

class ElectricEngine : IEngine {

public:
  ElectricEngine(Power power, BatteryCapacity batteryCapacity);
  ~ElectricEngine();
  void start() const override;
  void stop() const override;

private:
  Power power_;                     // in HP
  BatteryCapacity batteryCapacity_; // in Ah
};
