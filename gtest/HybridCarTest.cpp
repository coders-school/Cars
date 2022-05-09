#include <gtest/gtest.h>
#include <memory>
#include "../PetrolEngine.hpp"
#include "../PetrolCar.hpp"
#include "../InvalidGear.hpp"
#include "../ElectricEngine.hpp"
#include "../ElectricCar.hpp"
#include "../HybridCar.hpp"
#include "CarsTestsFixture.hpp"

TEST_F(CarsTests, ShouldBrakeThrowInvalidArgumentInHybridCarWhenCurrentSpeed0)
{
    EXPECT_THROW(toyota.brake(), std::invalid_argument);
}

TEST_F(CarsTests, ShouldAccelerateThrowInvalidArgumentInHybridCarWhenSpeedBelow0)
{
    EXPECT_THROW(toyota.accelerate(-50), std::invalid_argument);
}

TEST_F(CarsTests, ShouldAccelerateThrowInvalidArgumentInHybridCarWhenSpeedHigherThan200)
{
    EXPECT_THROW(nissan.accelerate(250), std::invalid_argument);
}
