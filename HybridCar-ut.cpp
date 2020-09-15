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
constexpr int currentGear = 2;

struct HybridCarTest : public ::testing::Test {
    HybridCar testHybridCar{new PetrolEngine(basePower, baseCapacity, baseGears), new ElectricEngine(basePower, baseBatteryCapacity)};
};

TEST_F(HybridCarTest, ShouldRetrunHybridCarEnginePower) {
    EXPECT_EQ(baseHybridPower, testHybridCar.getEnginePower());
}

TEST_F(HybridCarTest, ShouldReturnHybridCarVelocity) {
    testHybridCar.setSpeed(baseSpeed);
    EXPECT_EQ(baseSpeed, testHybridCar.getSpeed());
}

TEST_F(HybridCarTest, ShouldReturnHybridCarBatteryCapacity) {
    EXPECT_EQ(baseBatteryCapacity, testHybridCar.getBatteryCapacity());
}

TEST_F(HybridCarTest, ShouldChangeHybridCarVelocity) {
    testHybridCar.accelerate(baseSpeed);
    EXPECT_EQ(baseSpeed, testHybridCar.getSpeed());
}

TEST_F(HybridCarTest, ShouldNotChangeVelocityOfHybridCarWhenInputVelocityIsNegativeValue) {
    const int negativeVelocity = -1;
    EXPECT_THROW(testHybridCar.accelerate(negativeVelocity), InvalidSpeed);
}

TEST_F(HybridCarTest, BrakingShouldSetSpeedToZeroForHybridCar) {
    const int expectedVelocityAfterBreaking = 0;
    testHybridCar.accelerate(baseSpeed);
    testHybridCar.brake();
    int resultSpeed = testHybridCar.getSpeed();
    EXPECT_EQ(resultSpeed, expectedVelocityAfterBreaking);
}

TEST_F(HybridCarTest, ShouldChangePetrolEngineForHybridCarWhenVelocityIsZero) {
    testHybridCar.brake();
    EXPECT_NO_THROW(testHybridCar.changeEngine(new PetrolEngine(basePower, baseCapacity, baseGears)));
}

TEST_F(HybridCarTest, ShouldChangeElectricEngineForHybridCarWhenVelocityIsZero) {
    testHybridCar.brake();
    EXPECT_NO_THROW(testHybridCar.changeEngine(new ElectricEngine(basePower, baseBatteryCapacity)));
}

TEST_F(HybridCarTest, ShouldChangeBothEnginesForHybridCarWhenVelocityIsZero) {
    testHybridCar.brake();
    EXPECT_NO_THROW(testHybridCar.changeEngine(new PetrolEngine(basePower, baseCapacity, baseGears)));
    EXPECT_NO_THROW(testHybridCar.changeEngine(new ElectricEngine(basePower, baseBatteryCapacity)));
}

TEST_F(HybridCarTest, ShouldChangeGearInHybridCar) {
    testHybridCar.changeGear(currentGear);
    EXPECT_EQ(currentGear, testHybridCar.getCurrentGear());
}

TEST_F(HybridCarTest, ShouldNOtChangeGearFromHigherGearThanNeutralToRearGearInHybridCar) {
    const int rearGear = -1;
    testHybridCar.changeGear(currentGear);
    EXPECT_THROW(testHybridCar.changeGear(rearGear), InvalidGear);
}

TEST_F(HybridCarTest, ShouldNotChangeGearInHybridCarIfThatGearDoesntExist) {
    const int minRange = -2;
    const int maxRange = baseGears + 1;
    EXPECT_THROW(testHybridCar.changeGear(minRange), InvalidGear);
    EXPECT_THROW(testHybridCar.changeGear(maxRange), InvalidGear);
}