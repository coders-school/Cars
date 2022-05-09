#include <gtest/gtest.h>
#include <memory>
#include "../PetrolEngine.hpp"
#include "../PetrolCar.hpp"
#include "../InvalidGear.hpp"
#include "../ElectricEngine.hpp"
#include "../ElectricCar.hpp"
#include "../HybridCar.hpp"
#include "CarsTestsFixture.hpp"

TEST_F(CarsTests, ShouldChangeGearThrowInvalidGear)
{
  opel.changeGear(5);
  EXPECT_THROW(opel.changeGear(-1), InvalidGear);
}

TEST_F(CarsTests, ShouldBrakeThrowInvalidArgumentInPetrolCarWhenCurrentSpeed0)
{
  EXPECT_THROW(opel.brake(), std::invalid_argument);
}

TEST_F(CarsTests, ShouldAccelerateThrowInvalidArgumentInPetrolCarWhenSpeedBelow0)
{
  PetrolCar opel(std::make_unique<PetrolEngine>(PetrolEngine(120, 1800, 6)));
  EXPECT_THROW(opel.accelerate(-50), std::invalid_argument);
}

TEST_F(CarsTests, ShouldAccelerateThrowInvalidArgumentInPetrolCarWhenSpeedHigherThan200)
{
  EXPECT_THROW(opel.accelerate(250), std::invalid_argument);
}

TEST_F(CarsTests, ShouldChangeEngineThrowInvalidArgumentInPetrolCarWhenElectricEngineGiven)
{
  EXPECT_THROW(opel.changeEngine(std::make_unique<ElectricEngine>(120, 1800)), std::invalid_argument);
}
