#include <gtest/gtest.h>
#include "HybridCar.hpp"

struct HybridCarTest : ::testing::Test {
    HybridCar toyota = HybridCar(new PetrolEngine(80, 1400, 5), new ElectricEngine(100, 540));
};

TEST_F(HybridCarTest, checkAcceleration) {
    toyota.accelerate(50);
    ASSERT_EQ(toyota.getSpeed(), 50);
}

TEST_F(HybridCarTest, checkSetEngine) {
    ASSERT_EQ(toyota.getEnginePower(), 130);
    toyota.setEngine(150, 860);
    ASSERT_EQ(toyota.getEnginePower(), 150);
}
