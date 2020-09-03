#include <gtest/gtest.h>

#include "ElectricCar.hpp"
#include "PetrolEngine.hpp"

struct ElectricCarTest : ::testing::Test {
    ElectricCarTest()
        : nissan(new ElectricEngine(power, 650)) {}

    const int power = 130;
    ElectricCar nissan;
};

TEST_F(ElectricCarTest, shouldChangeEngines) {
    constexpr int newPower = 200;
    nissan.changeEngine(new ElectricEngine(newPower, 650));
    ASSERT_EQ(nissan.getElectricPower(), newPower);
}

TEST_F(ElectricCarTest, shouldPreventFromInvalidEngineChange) {
    nissan.changeEngine(new PetrolEngine(300, 5.6, 5));
    ASSERT_EQ(nissan.getElectricPower(), power);
}

TEST_F(ElectricCarTest, shouldNotChangeEngineDuringDriving) {
    nissan.accelerate(100);
    nissan.changeEngine(new ElectricEngine(power + 100, 400));
    ASSERT_EQ(nissan.getElectricPower(), power);
}

TEST_F(ElectricCarTest, shouldChangeSpeed) {
    constexpr int newSpeed = 100;
    ASSERT_EQ(nissan.getSpeed(), 0);
    nissan.accelerate(newSpeed);
    ASSERT_EQ(nissan.getSpeed(), newSpeed);
}

TEST_F(ElectricCarTest, shouldNotChangeSpeedToInvalidValue) {
    ASSERT_EQ(nissan.getSpeed(), 0);
    nissan.accelerate(-100);
    ASSERT_EQ(nissan.getSpeed(), 0);
}
