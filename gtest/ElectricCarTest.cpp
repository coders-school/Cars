#include <gtest/gtest.h>
#include <memory>
#include "../PetrolEngine.hpp"
#include "../PetrolCar.hpp"
#include "../InvalidGear.hpp"
#include "../ElectricEngine.hpp"
#include "../ElectricCar.hpp"
#include "../HybridCar.hpp"
#include "CarsTestsFixture.hpp"

TEST_F(CarsTests, ShouldBrakeThrowInvalidArgumentInElectricCarWhenCurrentSpeed0)
{
  EXPECT_THROW(nissan.brake(), std::invalid_argument);
}

TEST_F(CarsTests, ShouldAccelerateThrowInvalidArgumentInElectricCarWhenSpeedBelow0)
{
  EXPECT_THROW(nissan.accelerate(-50), std::invalid_argument);
}

TEST_F(CarsTests, ShouldAccelerateThrowInvalidArgumentInElectricCarWhenSpeedHigherThan200)
{
  EXPECT_THROW(nissan.accelerate(250), std::invalid_argument);
}

TEST_F(CarsTests, ShouldChangeEngineThrowInvalidArgumentInElectricCarWhenPetrolEngineGiven)
{
  EXPECT_THROW(nissan.changeEngine(std::make_unique<PetrolEngine>(120, 1800, 5)), std::invalid_argument);
}
