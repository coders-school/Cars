#include "Car.hpp"
#include "ElectricCar.hpp"
#include "ElectricEngine.hpp"
#include "Exceptions.hpp"
#include "gtest/gtest.h"

constexpr int power = 120;
constexpr int batteryCapacity = 700;

class ElectricCarTest : public ::testing::Test {
protected:
    ElectricCarTest() : electricCar(std::make_unique<ElectricEngine>(power, batteryCapacity)){};

    ElectricCar electricCar;
};

TEST_F(ElectricCarTest, ElectricCarCanAccelerate) {
    electricCar.accelerate(50);
    ASSERT_EQ(electricCar.getSpeed(), 50);
}

TEST_F(ElectricCarTest, ElectricCarCanDecelerate) {
    electricCar.accelerate(50);
    electricCar.decelerate(40);
    ASSERT_EQ(electricCar.getSpeed(), 10);
}

TEST_F(ElectricCarTest, ElectricCarCannotReachNegativeSpeed) {
    EXPECT_THROW(electricCar.accelerate(-2), InvalidAcceleration);
}

TEST_F(ElectricCarTest, ElectricCarCannotDecelerateToNegativeSpeed) {
    EXPECT_THROW(electricCar.decelerate(-2), InvalidAcceleration);
}

TEST_F(ElectricCarTest, ElectricCanChangeEngineToElectric) {
    int newPower = 150;
    int newBatteryCapacity = 750;
    ASSERT_EQ(electricCar.getPower(), power);
    electricCar.changeEngine(std::make_unique<ElectricEngine>(newPower, newBatteryCapacity));
    ASSERT_EQ(electricCar.getBatteryCapacity(), newBatteryCapacity);
}

TEST_F(ElectricCarTest, ElectricCannotChangeEngineDuringRide) {
    int newPower = 150;
    int newBatteryCapacity = 750;
    electricCar.accelerate(50);
    EXPECT_THROW(electricCar.changeEngine(std::make_unique<ElectricEngine>(newPower, newBatteryCapacity)),
                 InvalidEngineChange);
}

TEST_F(ElectricCarTest, ElectricCannotBeInitializedWithNegativeBatteryCapacity) {
    int newBatteryCapacity = -750;
    EXPECT_THROW(electricCar.changeEngine(std::make_unique<ElectricEngine>(power, newBatteryCapacity)),
                 InvalidParameter);
}

TEST_F(ElectricCarTest, ElectricCannotBeInitializedWithNegativePower) {
    int newPower = -150;
    EXPECT_THROW(electricCar.changeEngine(std::make_unique<ElectricEngine>(newPower, batteryCapacity)),
                 InvalidParameter);
}
