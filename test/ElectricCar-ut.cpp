#include <gtest/gtest.h>

#include "ElectricCar.hpp"
#include "ElectricEngine.hpp"

struct ElectricCarTest : public ::testing::Test {
    const int power = 500;
    const int capacity = 20;

    ElectricCar testCar{new ElectricEngine{power, capacity}};
};

TEST_F(ElectricCarTest, shouldAccelerate)
{
    // Given
    const int speed = 120;
    testCar.accelerate(speed);

    // When
    auto result = testCar.getSpeed();

    // Then
    ASSERT_EQ(result, speed);
}
