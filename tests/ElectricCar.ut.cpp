#include "ElectricCar.hpp"
#include "gtest/gtest.h"

constexpr int electricEnginePower = 100;
constexpr int batteryCapacity = 150;

constexpr int betterEnginePower = 150;
constexpr int betterBatteryCapacity = 200;

class ElectricCarTest : public ::testing::Test {
public:
    ElectricCarTest()
        : car(std::make_unique<ElectricEngine>(electricEnginePower, batteryCapacity)) {}

    ElectricCar car;
};

TEST_F(ElectricCarTest, ChangingEngineDouringDrivingShouldThrowException) {
    car.accelerate(40);
    EXPECT_THROW(car.changeEngine(std::make_unique<ElectricEngine>(betterEnginePower, betterBatteryCapacity)), InvalidEngineChange);
}

TEST_F(ElectricCarTest, IfSpeedHigherThanBrakePowerSpeedShouldBeReduceByBrakePower) {
    car.accelerate(50);
    car.brake(30);
    EXPECT_EQ(car.getSpeed(), 20);
}

TEST_F(ElectricCarTest, IfSpeedLowerThanBrakePowerSpeedShouldBeEqualToZero) {
    car.accelerate(70);
    car.brake(90);
    EXPECT_EQ(car.getSpeed(), 0);
}

TEST_F(ElectricCarTest, IfCarStayChangeEngineShouldBeCorrect) {
    car.accelerate(50);
    car.brake(51);
    car.changeEngine(std::make_unique<ElectricEngine>(betterEnginePower, betterBatteryCapacity));
    EXPECT_EQ(car.getPower(), betterEnginePower);
}
