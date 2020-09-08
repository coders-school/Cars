#include <gtest/gtest.h>
#include "ElectricCar.hpp"

struct ElectricCarTest : ::testing::Test {
    ElectricCar nissan = ElectricCar(new ElectricEngine(130, 650));
};

TEST_F(ElectricCarTest, checkAcceleration) {
    nissan.accelerate(50);
    ASSERT_EQ(nissan.getSpeed(), 50);
}

TEST_F(ElectricCarTest, checkSetEngine) {
    ASSERT_EQ(nissan.getEnginePower(), 130);
    nissan.setEngine(150, 860);
    ASSERT_EQ(nissan.getEnginePower(), 150);
}

