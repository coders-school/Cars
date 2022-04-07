#include <gtest/gtest.h>
#include <memory>
#include "PetrolEngine.hpp"
#include "PetrolCar.hpp"
#include "InvalidGear.hpp"
#include "ElectricEngine.hpp"
#include "ElectricCar.hpp"
#include "HybridCar.hpp"

// PETROL CAR //

TEST(CarsTests, ShouldChangeGearThrowInvalidGear)
{
  PetrolCar opel(std::make_unique<PetrolEngine>(PetrolEngine(120, 1800, 6)));
  opel.changeGear(5);
  EXPECT_THROW(opel.changeGear(-1), InvalidGear);
}

TEST(CarsTests, ShouldBrakeThrowInvalidArgumentInPetrolCarWhenCurrentSpeed0)
{
  PetrolCar opel(std::make_unique<PetrolEngine>(PetrolEngine(120, 1800, 6)));
  EXPECT_THROW(opel.brake(), std::invalid_argument);
}

TEST(CarsTests, ShouldAccelerateThrowInvalidArgumentInPetrolCarWhenSpeedBelow0)
{
  PetrolCar opel(std::make_unique<PetrolEngine>(PetrolEngine(120, 1800, 6)));
  EXPECT_THROW(opel.accelerate(-50), std::invalid_argument);
}

TEST(CarsTests, ShouldAccelerateThrowInvalidArgumentInPetrolCarWhenSpeedHigherThan200)
{
  PetrolCar opel(std::make_unique<PetrolEngine>(PetrolEngine(120, 1800, 6)));
  EXPECT_THROW(opel.accelerate(250), std::invalid_argument);
}

TEST(CarsTests, ShouldChangeEngineThrowInvalidArgumentInPetrolCarWhenElectricEngineGiven)
{
  PetrolCar opel(std::make_unique<PetrolEngine>(PetrolEngine(120, 1800, 6)));
  EXPECT_THROW(opel.changeEngine(std::make_unique<ElectricEngine>(120, 1800)), std::invalid_argument);
}

// ELECTRIC CAR //

TEST(CarsTests, ShouldBrakeThrowInvalidArgumentInElectricCarWhenCurrentSpeed0)
{
  ElectricCar nissan(std::make_unique<ElectricEngine>(ElectricEngine(130, 650)));
  EXPECT_THROW(nissan.brake(), std::invalid_argument);
}

TEST(CarsTests, ShouldAccelerateThrowInvalidArgumentInElectricCarWhenSpeedBelow0)
{
  ElectricCar nissan(std::make_unique<ElectricEngine>(ElectricEngine(130, 650)));
  EXPECT_THROW(nissan.accelerate(-50), std::invalid_argument);
}

TEST(CarsTests, ShouldAccelerateThrowInvalidArgumentInElectricCarWhenSpeedHigherThan200)
{
  ElectricCar nissan(std::make_unique<ElectricEngine>(ElectricEngine(130, 650)));
  EXPECT_THROW(nissan.accelerate(250), std::invalid_argument);
}

TEST(CarsTests, ShouldChangeEngineThrowInvalidArgumentInElectricCarWhenPetrolEngineGiven)
{
  ElectricCar nissan(std::make_unique<ElectricEngine>(ElectricEngine(130, 650)));
  EXPECT_THROW(nissan.changeEngine(std::make_unique<PetrolEngine>(120, 1800, 5)), std::invalid_argument);
}

// HYBRID CAR //

TEST(CarsTests, ShouldBrakeThrowInvalidArgumentInHybridCarWhenCurrentSpeed0)
{
  HybridCar toyota(std::make_unique<PetrolEngine>(PetrolEngine(80, 1400, 5)), std::make_unique<ElectricEngine>(ElectricEngine(100, 540)));
  EXPECT_THROW(toyota.brake(), std::invalid_argument);
}

TEST(CarsTests, ShouldAccelerateThrowInvalidArgumentInHybridCarWhenSpeedBelow0)
{
  HybridCar toyota(std::make_unique<PetrolEngine>(PetrolEngine(80, 1400, 5)), std::make_unique<ElectricEngine>(ElectricEngine(100, 540)));
  EXPECT_THROW(toyota.accelerate(-50), std::invalid_argument);
}

TEST(CarsTests, ShouldAccelerateThrowInvalidArgumentInHybridCarWhenSpeedHigherThan200)
{
  ElectricCar nissan(std::make_unique<ElectricEngine>(ElectricEngine(130, 650)));
  EXPECT_THROW(nissan.accelerate(250), std::invalid_argument);
}