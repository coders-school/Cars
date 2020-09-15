#include <stdint.h>

#include "ElectricEngine.hpp"
#include "InvalidEngineChange.hpp"
#include "InvalidGear.hpp"
#include "InvalidSpeed.hpp"
#include "PetrolCar.hpp"
#include "PetrolEngine.hpp"
#include "gtest/gtest.h"

constexpr uint16_t basePower = 100;
constexpr uint16_t baseBatteryCapacity = 200;
constexpr uint16_t baseCapacity = 1000;
constexpr uint8_t baseGears = 6;
constexpr int baseSpeed = 50;
constexpr int currentGear = 2;

struct PetrolCarTest : public ::testing::Test {
    PetrolCar testPetrolCar{new PetrolEngine(basePower, baseCapacity, baseGears)};
};

TEST_F(PetrolCarTest, ShouldRetrunPetrolCarEnginePower) {
    EXPECT_EQ(basePower, testPetrolCar.getEnginePower());
}

TEST_F(PetrolCarTest, ShouldReturnPetrolCarSpeed) {
    testPetrolCar.setSpeed(baseSpeed);
    EXPECT_EQ(baseSpeed, testPetrolCar.getSpeed());
}

TEST_F(PetrolCarTest, ShouldChangePetrolCarVelocity) {
    testPetrolCar.accelerate(baseSpeed);
    EXPECT_EQ(baseSpeed, testPetrolCar.getSpeed());
}

TEST_F(PetrolCarTest, ShouldNotChangeVelocityOfPetrolCarWhenInputVelocityIsNegativeValue) {
    const int negativeVelocity = -1;
    EXPECT_THROW(testPetrolCar.accelerate(negativeVelocity), InvalidSpeed);
}

TEST_F(PetrolCarTest, BreakingShouldSetSpeedToZeroForPetrolCar) {
    const int expectedVelocityAfterBreaking = 0;
    testPetrolCar.accelerate(baseSpeed);
    testPetrolCar.brake();
    int resultSpeed = testPetrolCar.getSpeed();
    EXPECT_EQ(resultSpeed, expectedVelocityAfterBreaking);
}

TEST_F(PetrolCarTest, ShouldChangeGearInPetrolCar) {
    testPetrolCar.changeGear(currentGear);
    EXPECT_EQ(currentGear, testPetrolCar.getCurrentGear());
}

TEST_F(PetrolCarTest, ShouldntChangeGearFromHigherGearThanNeturalToRearGearInPetrolCar) {
    const int rearGear = -1;
    testPetrolCar.changeGear(currentGear);
    EXPECT_THROW(testPetrolCar.changeGear(rearGear), InvalidGear);
}

TEST_F(PetrolCarTest, ShouldntChangeGearInPetrolCarForWrongRange) {
    const int minRange = -2;
    const int maxRange = baseGears + 1;
    EXPECT_THROW(testPetrolCar.changeGear(minRange), InvalidGear);
    EXPECT_THROW(testPetrolCar.changeGear(maxRange), InvalidGear);
}

TEST_F(PetrolCarTest, ShouldChangeEngineForPetrolCarWhenVelocityIsZero) {
    testPetrolCar.brake();
    EXPECT_NO_THROW(testPetrolCar.changeEngine(new PetrolEngine(basePower, baseCapacity, baseGears)));
}

TEST_F(PetrolCarTest, ShouldNotChangeEngineForPetrolCarWhenCarIsSpeeding) {
    testPetrolCar.accelerate(baseSpeed);
    EXPECT_THROW(testPetrolCar.changeEngine(new PetrolEngine(basePower, baseCapacity, baseGears)), InvalidEngineChange);
}

TEST_F(PetrolCarTest, ShouldNotChangeEngineForPetrolCarWhenNewEngineIsDiffernetType) {
    testPetrolCar.brake();
    EXPECT_THROW(testPetrolCar.changeEngine(new ElectricEngine(basePower, baseBatteryCapacity)), InvalidEngineChange);
}
