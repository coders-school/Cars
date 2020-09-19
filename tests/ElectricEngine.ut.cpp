#include "gtest/gtest.h"
#include "ElectricEngine.hpp"


constexpr int electricEnginePower = 100;
constexpr int batteryCapacity = 200;

TEST(ElectricEngineTest, GettersShouldReturnProperBatteryCapacityAndEnginePower){
    ElectricEngine electricEngine(electricEnginePower, batteryCapacity);
    EXPECT_EQ(electricEngine.getPower(), electricEnginePower);
    EXPECT_EQ(electricEngine.getBatteryCapacity(), batteryCapacity);
}
