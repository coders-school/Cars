#include <stdint.h>

#include "ElectricEngine.hpp"
#include "HybridCar.hpp"
#include "InvalidEngineChange.hpp"
#include "InvalidGear.hpp"
#include "InvalidSpeed.hpp"
#include "PetrolEngine.hpp"
#include "gtest/gtest.h"

constexpr uint16_t basePower = 100;
constexpr uint16_t baseHybridPower = basePower + basePower;
constexpr uint16_t baseBatteryCapacity = 200;
constexpr uint16_t baseCapacity = 1000;
constexpr uint8_t baseGears = 6;
constexpr int baseSpeed = 50;

struct CarsTest : public ::testing::Test {
    HybridCar testHybridCar{new PetrolEngine(basePower, baseCapacity, baseGears), new ElectricEngine(basePower, baseBatteryCapacity)};
};

//TEST_F(CarsTest, ShouldRetrunHybridCarEnginePower) {
//  EXPECT_EQ(baseHybridPower, testHybridCar.getEnginePower());
//}

TEST_F(CarsTest, ShouldReturnHybridCarSpeed) {
    testHybridCar.setSpeed(baseSpeed);
    EXPECT_EQ(baseSpeed, testHybridCar.getSpeed());
}

TEST_F(CarsTest, ShouldChangeHybridCarVelocity) {
    testHybridCar.accelerate(baseSpeed);
    EXPECT_EQ(baseSpeed, testHybridCar.getSpeed());
}

TEST_F(CarsTest, ShouldNotChangeVelocityOfHybridCarWhenInputVelocityIsNegativeValue) {
    const int negativeVelocity = -1;
    EXPECT_THROW(testHybridCar.accelerate(negativeVelocity), InvalidSpeed);
}

TEST_F(CarsTest, BreakingShouldSetSpeedToZeroForHybridCar) {
    const int expectedVelocityAfterBreaking = 0;
    testHybridCar.accelerate(baseSpeed);
    testHybridCar.brake();
    int resultSpeed = testHybridCar.getSpeed();
    EXPECT_EQ(resultSpeed, expectedVelocityAfterBreaking);
}

TEST_F(CarsTest, ShouldChangeEngineForHybridCarWhenVelocityIsZero) {
    testHybridCar.brake();
    EXPECT_NO_THROW(testHybridCar.changeEngine(new PetrolEngine(basePower, baseCapacity, baseGears)));
    //EXPECT_NO_THROW(testHybridCar.changeEngine(new ElectricEngine(basePower, baseBatteryCapacity)));
}
