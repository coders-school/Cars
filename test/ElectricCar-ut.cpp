#include <gtest/gtest.h>

#include "ElectricCar.hpp"
#include "ElectricEngine.hpp"
#include "InvalidEngine.hpp"
#include "MovingCar.hpp"
#include "PetrolEngine.hpp"

struct ElectricCarTest : public ::testing::Test {
    const int power = 500;
    const int capacity = 20;

    const int newSpeed = 120;
    const int newPower = 666;
    const int newCapacity = 777;
    const int newGears = 6;

    ElectricCar testCar{new ElectricEngine{power, capacity}};
};

TEST_F(ElectricCarTest, shouldAccelerate)
{
    // Given
    // When
    testCar.accelerate(newSpeed);
    auto result = testCar.getSpeed();

    // Then
    ASSERT_EQ(result, newSpeed);
}

TEST_F(ElectricCarTest, shouldNotAccelerate)
{
    // Given
    // When
    auto before = testCar.getSpeed();
    testCar.accelerate(-1 * newSpeed);
    auto after = testCar.getSpeed();

    // Then
    ASSERT_EQ(before, after);
}

TEST_F(ElectricCarTest, shouldNotThrowAnyExceptionWhenTryToReplaceEngine)
{
    // Given
    // When
    // Then
    ASSERT_NO_THROW(testCar.changeEngine(new ElectricEngine{newPower, newCapacity}));
}

TEST_F(ElectricCarTest, shouldThrowMovingCarWhenTryToReplaceEngine)
{
    // Given
    // When
    testCar.accelerate(newSpeed);    

    // Then
    ASSERT_THROW(testCar.changeEngine(new ElectricEngine{newPower, newCapacity}), MovingCar);
}

TEST_F(ElectricCarTest, shouldThrowInvalidEngineWhenTryToReplaceEngine)
{
    // Given
    // When
    // Then
    ASSERT_THROW(testCar.changeEngine(new PetrolEngine{newPower, float(newCapacity), newGears}), InvalidEngine);
}

TEST_F(ElectricCarTest, shouldUpdatePowerAfterEngineChange)
{
    // Given
    // When
    testCar.changeEngine(new ElectricEngine{newPower, newCapacity});
    auto result = testCar.getEnginePower();

    // Then
    ASSERT_EQ(result, newPower);
}
