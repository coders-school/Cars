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

struct CarsTest : public ::testing::Test {
    PetrolCar testPetrolCar{new PetrolEngine(basePower, baseCapacity, baseGears)};
};

TEST_F(CarsTest, ShouldRetrunPetrolCarEnginePower) {
    EXPECT_EQ(basePower, testPetrolCar.getEnginePower());
}

TEST_F(CarsTest, ShouldReturnPetrolCarSpeed) {
    testPetrolCar.setSpeed(baseSpeed);
    EXPECT_EQ(baseSpeed, testPetrolCar.getSpeed());
}

TEST_F(CarsTest, ShouldChangePetrolCarVelocity) {
    testPetrolCar.accelerate(baseSpeed);
    EXPECT_EQ(baseSpeed, testPetrolCar.getSpeed());
}

TEST_F(CarsTest, ShouldNotChangeVelocityOfPetrolCarWhenInputVelocityIsNegativeValue) {
    const int negativeVelocity = -1;
    EXPECT_THROW(testPetrolCar.accelerate(negativeVelocity), InvalidSpeed);
}

TEST_F(CarsTest, BreakingShouldSetSpeedToZeroForPetrolCar) {
    const int expectedVelocityAfterBreaking = 0;
    testPetrolCar.accelerate(baseSpeed);
    testPetrolCar.brake();
    int resultSpeed = testPetrolCar.getSpeed();
    EXPECT_EQ(resultSpeed, expectedVelocityAfterBreaking);
}

TEST_F(CarsTest, ShouldChangeEngineForPetrolCarWhenVelocityIsZero) {
    testPetrolCar.brake();
    EXPECT_NO_THROW(testPetrolCar.changeEngine(new PetrolEngine(basePower, baseCapacity, baseGears)));
}

TEST_F(CarsTest, ShouldNotChangeEngineForPetrolCarWhenCarIsSpeeding) {
    testPetrolCar.accelerate(baseSpeed);
    EXPECT_THROW(testPetrolCar.changeEngine(new PetrolEngine(basePower, baseCapacity, baseGears)), InvalidEngineChange);
}

TEST_F(CarsTest, ShouldNotChangeEngineForPetrolCarWhenNewEngineIsDiffernetType) {
    testPetrolCar.brake();
    EXPECT_THROW(testPetrolCar.changeEngine(new ElectricEngine(basePower, baseBatteryCapacity)), InvalidEngineChange);
}
