#include "gtest/gtest.h"

#include "ElectricCar.hpp"
#include "ElectricEngine.hpp"
#include "ExceptionsCars.hpp"

struct ElectricCarTest : ::testing::Test {
    ElectricCar electricCar = ElectricCar(new ElectricEngine(120, 1800));
};

TEST_F(ElectricCarTest, ShouldNotThrowInvalidAccelerateWhenTryToAccelerateWithPositiveNumber)
{
    EXPECT_NO_THROW(electricCar.accelerate(50));
    EXPECT_NO_THROW(electricCar.accelerate(40));
    EXPECT_NO_THROW(electricCar.accelerate(900));
    EXPECT_NO_THROW(electricCar.accelerate(4.4));
    EXPECT_NO_THROW(electricCar.accelerate(444.9));
}

TEST_F(ElectricCarTest, ShouldThrowInvalidAccelerateWhenTryToAccelerateWithNegativeNumber)
{
    EXPECT_THROW(electricCar.accelerate(-500), InvalidAccelerate);
    EXPECT_THROW(electricCar.accelerate(-115.10), InvalidAccelerate);
    EXPECT_THROW(electricCar.accelerate(-54.0), InvalidAccelerate);
    EXPECT_THROW(electricCar.accelerate(-5.40), InvalidAccelerate);
}
