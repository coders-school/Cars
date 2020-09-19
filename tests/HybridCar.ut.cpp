#include "HybridCar.hpp"
#include "gtest/gtest.h"

constexpr int enginePower = 100;
constexpr float engineCapacity = 8.0;
constexpr int engineGears = 6;

constexpr int electringEnginePower = 150;
constexpr int batteryCapacity = 80;

constexpr int newEnginePower = 150;
constexpr float newEngineCapacity = 9.0;
constexpr int newEngineGears = 8;

constexpr int newElectricEnginePower = 200;
constexpr int newBatteryCapacity = 160;

TEST(HybridCarTest, IfEnginesWasChangedForOtherEnginesGetPowerAndGetCapacityShouldReturnOtherValues) {
    HybridCar hybrid(
        std::make_unique<PetrolEngine>(enginePower, engineCapacity, engineGears),
        std::make_unique<ElectricEngine>(electringEnginePower, batteryCapacity));

    hybrid.changeEngine(
        std::make_unique<PetrolEngine>(newEnginePower, newEngineCapacity, newEngineGears),
        std::make_unique<ElectricEngine>(newElectricEnginePower, newBatteryCapacity));
    
    EXPECT_EQ(hybrid.getPetrolEnginePower(),newEnginePower);
    EXPECT_FLOAT_EQ(hybrid.getPetrolEngineCapacity(), newEngineCapacity);
    EXPECT_EQ(hybrid.getPower(), newElectricEnginePower);
    EXPECT_EQ(hybrid.getBatteryCapacity(), newBatteryCapacity);

}
