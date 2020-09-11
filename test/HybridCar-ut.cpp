#include <gtest/gtest.h>

#include "ElectricEngine.hpp"
#include "InvalidEngine.hpp"
#include "InvalidGear.hpp"
#include "HybridCar.hpp"
#include "MovingCar.hpp"
#include "PetrolEngine.hpp"

struct HybridCarTest : public ::testing::Test {
    const int petrolPower = 500;
    const float petrolCapacity = 20;
    const int petrolGears = 4;

    const int electricPower = 43;
    const int electricCapacity = 75;

    const int newSpeed = 120;
    const int newPower = 666;
    const float newCapacity = 777;
    const int newGears = 6;

    HybridCar testCar{new PetrolEngine{petrolPower, petrolCapacity, petrolGears}, 
                          new ElectricEngine{electricPower, electricCapacity}};
};

TEST_F(HybridCarTest, shouldAccelerate)
{
    // Given
    // When
    testCar.accelerate(newSpeed);
    auto result = testCar.getSpeed();

    // Then
    ASSERT_EQ(result, newSpeed);
}

TEST_F(HybridCarTest, shouldNotAccelerate)
{
    // Given
    // When
    auto before = testCar.getSpeed();
    testCar.accelerate(-1 * newSpeed);
    auto after = testCar.getSpeed();

    // Then
    ASSERT_EQ(before, after);
}

TEST_F(HybridCarTest, shouldNotThrowAnyExceptionWhenTryToReplaceEngine)
{
    // Given
    // When
    // Then
    ASSERT_NO_THROW(testCar.changeEngine(new PetrolEngine{newPower, newCapacity, newGears}));
    ASSERT_NO_THROW(testCar.changeEngine(new ElectricEngine{newPower, int(newCapacity)}));
}

TEST_F(HybridCarTest, shouldThrowMovingCarWhenTryToReplaceEngine)
{
    // Given
    // When
    testCar.accelerate(newSpeed);    

    // Then
    ASSERT_THROW(testCar.changeEngine(new PetrolEngine{newPower, newCapacity, newGears}), MovingCar);
}

TEST_F(HybridCarTest, shouldThrowInvalidEngineWhenTryToReplaceEngine)
{
    // Given
    // When
    // Then
    ASSERT_THROW(testCar.changeEngine(new Engine{newPower}), InvalidEngine);
}

TEST_F(HybridCarTest, shouldUpdateGear)
{
    // Given
    constexpr int gearToSet = 1;

    // When
    testCar.setGear(gearToSet);
    auto result = testCar.getGear();

    // Then
    ASSERT_EQ(result, gearToSet);
}

TEST_F(HybridCarTest, shouldThrowInvalidGearForGearOutOfRange)
{
    // Given
    const int gearToSet = petrolGears + 1;

    // When
    // Then
    ASSERT_THROW(testCar.setGear(gearToSet), InvalidGear);
}

TEST_F(HybridCarTest, shouldThrowInvalidGearForSettingRearNotFromNeutral)
{
    // Given
    constexpr int gearToSet = 1;

    // When
    testCar.setGear(gearToSet);

    // Then
    ASSERT_THROW(testCar.setGear(-1), InvalidGear);
}

TEST_F(HybridCarTest, shouldThrowInvalidGearForSettingNonNeutralFromRear)
{
    // Given
    constexpr int gearToSet = -1;

    // When
    testCar.setGear(gearToSet);

    // Then
    ASSERT_THROW(testCar.setGear(petrolGears), InvalidGear);
}
