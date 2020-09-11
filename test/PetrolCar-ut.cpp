#include <gtest/gtest.h>

#include "ElectricEngine.hpp"
#include "InvalidEngine.hpp"
#include "InvalidGear.hpp"
#include "MovingCar.hpp"
#include "PetrolCar.hpp"
#include "PetrolEngine.hpp"

struct PetrolCarTest : public ::testing::Test {
    const int power = 500;
    const float capacity = 20;
    const int gears = 4;

    const int newSpeed = 120;
    const int newPower = 666;
    const float newCapacity = 777;
    const int newGears = 6;

    PetrolCar testCar{new PetrolEngine{power, capacity, gears}};
};

TEST_F(PetrolCarTest, shouldAccelerate)
{
    // Given
    // When
    testCar.accelerate(newSpeed);
    auto result = testCar.getSpeed();

    // Then
    ASSERT_EQ(result, newSpeed);
}

TEST_F(PetrolCarTest, shouldNotAccelerate)
{
    // Given
    // When
    auto before = testCar.getSpeed();
    testCar.accelerate(-1 * newSpeed);
    auto after = testCar.getSpeed();

    // Then
    ASSERT_EQ(before, after);
}

TEST_F(PetrolCarTest, shouldNotThrowAnyExceptionWhenTryToReplaceEngine)
{
    // Given
    // When
    // Then
    ASSERT_NO_THROW(testCar.changeEngine(new PetrolEngine{newPower, newCapacity, newGears}));
}

TEST_F(PetrolCarTest, shouldThrowMovingCarWhenTryToReplaceEngine)
{
    // Given
    // When
    testCar.accelerate(newSpeed);    

    // Then
    ASSERT_THROW(testCar.changeEngine(new PetrolEngine{newPower, newCapacity, newGears}), MovingCar);
}

TEST_F(PetrolCarTest, shouldThrowInvalidEngineWhenTryToReplaceEngine)
{
    // Given
    // When
    // Then
    ASSERT_THROW(testCar.changeEngine(new ElectricEngine{newPower, int(newCapacity)}), InvalidEngine);
}

TEST_F(PetrolCarTest, shouldUpdatePowerAfterEngineChange)
{
    // Given
    // When
    testCar.changeEngine(new PetrolEngine{newPower, newCapacity, newGears});
    auto result = testCar.getEnginePower();

    // Then
    ASSERT_EQ(result, newPower);
}

TEST_F(PetrolCarTest, shouldUpdateGear)
{
    // Given
    constexpr int gearToSet = 1;

    // When
    testCar.setGear(gearToSet);
    auto result = testCar.getGear();

    // Then
    ASSERT_EQ(result, gearToSet);
}

TEST_F(PetrolCarTest, shouldThrowInvalidGearForGearOutOfRange)
{
    // Given
    const int gearToSet = gears + 1;

    // When
    // Then
    ASSERT_THROW(testCar.setGear(gearToSet), InvalidGear);
}

TEST_F(PetrolCarTest, shouldThrowInvalidGearForSettingRearNotFromNeutral)
{
    // Given
    constexpr int gearToSet = 1;

    // When
    testCar.setGear(gearToSet);

    // Then
    ASSERT_THROW(testCar.setGear(-1), InvalidGear);
}

TEST_F(PetrolCarTest, shouldThrowInvalidGearForSettingNonNeutralFromRear)
{
    // Given
    constexpr int gearToSet = -1;

    // When
    testCar.setGear(gearToSet);

    // Then
    ASSERT_THROW(testCar.setGear(gears), InvalidGear);
}
