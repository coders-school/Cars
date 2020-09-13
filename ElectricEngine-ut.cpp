#include <gtest/gtest.h>
#include "ElectricEngine.hpp"

TEST(ElectricEngineTest, shouldInitPowerAndBatteryCapacity)
{
    //GIVEN
    ElectricEngine engine = ElectricEngine(150, 123);
    // WHEN, THEN
    EXPECT_EQ(engine.getPower(), 150);
    EXPECT_EQ(engine.getBatteryCapacity(), 123);
}