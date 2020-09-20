#include "gtest/gtest.h"

#include "HybridCar.hpp"
#include "ElectricEngine.hpp"
#include "ExceptionsCars.hpp"

struct HybridCarTest : ::testing::Test {
    HybridCar hybridCar = HybridCar(new PetrolEngine(120, 1800, 6), new ElectricEngine(120, 1800));
};


TEST_F(HybridCarTest, ShouldNotThrowInvalidAccelerateWhenTryToAccelerateWithPositiveNumber)
{
    EXPECT_NO_THROW(hybridCar.accelerate(50));
    EXPECT_NO_THROW(hybridCar.accelerate(40));
    EXPECT_NO_THROW(hybridCar.accelerate(900));
    EXPECT_NO_THROW(hybridCar.accelerate(4.4));
    EXPECT_NO_THROW(hybridCar.accelerate(444.9));
}

TEST_F(HybridCarTest, ShouldThrowInvalidAccelerateWhenTryToAccelerateWithNegativeNumber)
{
    EXPECT_THROW(hybridCar.accelerate(-500), InvalidAccelerate);
    EXPECT_THROW(hybridCar.accelerate(-115.10), InvalidAccelerate);
    EXPECT_THROW(hybridCar.accelerate(-54.0), InvalidAccelerate);
    EXPECT_THROW(hybridCar.accelerate(-5.40), InvalidAccelerate);
}
