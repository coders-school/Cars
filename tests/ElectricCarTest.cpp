#include <gtest/gtest.h>
#include "ElectricCar.hpp"

struct ElectricCarTest : ::testing::Test {
        ElectricCar car{new ElectricEngine{HorsePower(200), AmpereHour(1600)}};

};

TEST_F(ElectricCarTest, BatteryLevelShouldBeFullAtStart) {
    auto expectedBatteryLevel = car.getEngine().getBatterCapacity();
    EXPECT_EQ(expectedBatteryLevel.value_, car.getBatteryLevel().value_); 
}

TEST_F(ElectricCarTest, BatteryLevelShouldBeFullAfterRestore) {
    auto expectedBatteryLevel = car.getEngine().getBatterCapacity();
    car.restore();
    EXPECT_EQ(expectedBatteryLevel.value_, car.getBatteryLevel().value_); 
}
