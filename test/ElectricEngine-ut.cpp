#include <gtest/gtest.h>

#include "ElectricEngine.hpp"

struct ElectricEngineTest : public ::testing::Test {

};

TEST_F(ElectricEngineTest, batteryCapacitySetByConstructor)
{
    // Given
    constexpr int batCapacity = 50;
    ElectricEngine elEng{100, batCapacity};

    // When
    auto result = elEng.getBatteryCapacity();

    // Then
    ASSERT_EQ(result, batCapacity);
}
