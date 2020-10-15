#include <gtest/gtest.h>

#include "Car.hpp"
#include "ElectricCar.hpp"
#include "ElectricEngine.hpp"
#include "InvalidEngine.hpp"
#include "InvalidSpeed.hpp"

constexpr int power = 120;
constexpr int batteryCapacity = 700;
constexpr int speed = 120;

class ElectricCarTest : public ::testing::Test {
protected:
    ElectricCar electricCarTest;
    ElectricCarTest()
        : electricCarTest(std::make_shared<ElectricEngine>(power, batteryCapacity)){};
};

TEST_F(ElectricCarTest, ShouldChangeElectricCarVelocity) {
    electricCarTest.accelerate(speed);
    EXPECT_EQ(speed, electricCarTest.getSpeed());
}

TEST_F(ElectricCarTest, ShouldReturnElectricCarEnginePower) {
    EXPECT_EQ(power, electricCarTest.getPower());
}

TEST_F(ElectricCarTest, ShouldReturnElectricCarBatteryCapacity) {
    EXPECT_EQ(batteryCapacity, electricCarTest.getBatteryCapacity());
}

TEST_F(ElectricCarTest, ShouldNotChangeVelocityOfElectricCarWhenInputVelocityIsNegativeValue) {
    constexpr int negativeSpeed = -120;
    EXPECT_THROW(electricCarTest.accelerate(negativeSpeed), InvalidSpeed);
}

TEST_F(ElectricCarTest, ShouldChangeEngineForElectricCar) {
    constexpr int newPower = 666;
    constexpr int newCapacity = 777;
    ASSERT_EQ(electricCarTest.getPower(), power);
    electricCarTest.changeEngine(std::make_shared<ElectricEngine>(newPower, newCapacity));
    ASSERT_EQ(electricCarTest.getBatteryCapacity(), newCapacity);
}

TEST_F(ElectricCarTest, ShouldNotChangeEngineForElectricCar) {
    constexpr int newPower = 666;
    constexpr int newCapacity = 777;
    electricCarTest.accelerate(speed);
    EXPECT_THROW(electricCarTest.changeEngine(std::make_shared<ElectricEngine>(newPower, newCapacity)), InvalidEngine);
}
