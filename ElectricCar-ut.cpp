#include "ElectricCar.hpp"
#include "ElectricEngine.hpp"
#include "InvalidEngineChange.hpp"
#include "InvalidSpeed.hpp"
#include "PetrolEngine.hpp"
#include "gtest/gtest.h"

constexpr uint16_t basePower = 100;
constexpr uint16_t baseBatteryCapacity = 200;
constexpr uint16_t baseCapacity = 1000;
constexpr uint8_t baseGears = 6;
constexpr int baseSpeed = 50;

struct ElectricCarTest : public ::testing::Test {
    ElectricCar testElectricCar{new ElectricEngine(basePower, baseBatteryCapacity)};
};
TEST_F(ElectricCarTest, ShouldRetrunElectricCarEnginePower) {
    EXPECT_EQ(basePower, testElectricCar.getEnginePower());
}

TEST_F(ElectricCarTest, ShouldReturnElectricCarVelocity) {
    testElectricCar.setSpeed(baseSpeed);
    EXPECT_EQ(baseSpeed, testElectricCar.getSpeed());
}

TEST_F(ElectricCarTest, ShouldReturnElectricCarBatteryCapacity) {
    EXPECT_EQ(baseBatteryCapacity, testElectricCar.getBatteryCapacity());
}

TEST_F(ElectricCarTest, ShouldChangeElectricCarVelocity) {
    testElectricCar.accelerate(baseSpeed);
    EXPECT_EQ(baseSpeed, testElectricCar.getSpeed());
}

TEST_F(ElectricCarTest, ShouldNotChangeVelocityOfElectricCarWhenInputVelocityIsNegativeValue) {
    const int negativeVelocity = -1;
    EXPECT_THROW(testElectricCar.accelerate(negativeVelocity), InvalidSpeed);
}

TEST_F(ElectricCarTest, BrakingShouldSetSpeedToZeroForElectricCar) {
    const int expectedVelocityAfterBreaking = 0;
    testElectricCar.accelerate(baseSpeed);
    testElectricCar.brake();
    int resultSpeed = testElectricCar.getSpeed();
    EXPECT_EQ(resultSpeed, expectedVelocityAfterBreaking);
}

TEST_F(ElectricCarTest, ShouldChangeEngineForElectricCarWhenVelocityIsZero) {
    testElectricCar.brake();
    EXPECT_NO_THROW(testElectricCar.changeEngine(new ElectricEngine(basePower, baseBatteryCapacity)));
}

TEST_F(ElectricCarTest, ShouldNotChangeEngineForElectricCarWhenCarVelocityIsNotZero) {
    testElectricCar.accelerate(baseSpeed);
    EXPECT_THROW(testElectricCar.changeEngine(new ElectricEngine(basePower, baseBatteryCapacity)), InvalidEngineChange);
}

TEST_F(ElectricCarTest, ShouldNotChangeEngineForElectricCarWhenNewEngineIsDiffernetType) {
    testElectricCar.brake();
    EXPECT_THROW(testElectricCar.changeEngine(new PetrolEngine(basePower, baseBatteryCapacity, baseGears)), InvalidEngineChange);
}
