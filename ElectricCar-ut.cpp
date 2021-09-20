#include <gtest/gtest.h>
#include <memory>
#include <stdexcept>

#include "ElectricCar.hpp"
#include "ElectricEngine.hpp"
#include "InvalidEngineChange.hpp"
#include "InvalidSpeed.hpp"
#include "InvalidParameter.hpp"

struct ElectricCarTest : ::testing::Test {
    int power{ 110 };
    float battery_capacity{ 700 };
    ElectricCar electricCar{ std::make_unique<ElectricEngine>(power, battery_capacity) };
};

TEST_F(ElectricCarTest, ShouldAccelerateProperly) {
    electricCar.accelerate(42);
    EXPECT_EQ(electricCar.getSpeed(), 42);    
}

TEST_F(ElectricCarTest, ShoulNotAccelerateButThrowException) {
    EXPECT_THROW(electricCar.accelerate(-42), InvalidSpeed);    
}

TEST_F(ElectricCarTest, ShouldBrake) {
    electricCar.brake();
    EXPECT_EQ(electricCar.getSpeed(), 0);
}

TEST_F(ElectricCarTest, EngineShouldBeChangedWhenStopped) {
    EXPECT_NO_THROW(electricCar.changeEngine(std::make_unique<ElectricEngine>(power, battery_capacity)));
}

TEST_F(ElectricCarTest, EngineNotShouldBeChangedWhileDriving) {
    electricCar.accelerate(42);
    EXPECT_THROW(electricCar.changeEngine(std::make_unique<ElectricEngine>(power, battery_capacity)),
                 InvalidEngineChange);
}

TEST_F(ElectricCarTest, EngingeCannotBeInitializedWithNegativeCapacity) {
    battery_capacity = -700;
    EXPECT_THROW(electricCar.changeEngine(std::make_unique<ElectricEngine>(power, battery_capacity)),
                 InvalidParameter);
}

TEST_F(ElectricCarTest, EngingeCannotBeInitializedWithNegativePower) {
    power = -110;
    EXPECT_THROW(electricCar.changeEngine(std::make_unique<ElectricEngine>(power, battery_capacity)),
                 InvalidParameter);
}
