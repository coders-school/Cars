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

TEST_F(ElectricCarTest, shoudldNotThrowAnyExceptionWhenTryToReplaceEngine)
{
    // Given
    // When
    // Then
    ASSERT_NO_THROW(testCar.changeEngine(new ElectricEngine{666, 777}));
}

TEST_F(ElectricCarTest, shoudldThrowMovingCarWhenTryToReplaceEngine)
{
    // Given
    // When
    testCar.accelerate(newSpeed);    

    // Then
    ASSERT_THROW(testCar.changeEngine(new ElectricEngine{666, 777}), MovingCar);
}

TEST_F(ElectricCarTest, shoudldThrowInvalidEngineWhenTryToReplaceEngine)
{
    // Given
    // When
    // Then
    ASSERT_THROW(testCar.changeEngine(new PetrolEngine{999, 123, 6}), InvalidEngine);
}
