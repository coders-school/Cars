#include <gtest/gtest.h>
#include <memory>
#include "PetrolEngine.hpp"
#include "PetrolCar.hpp"
#include "InvalidGear.hpp"
#include "ElectricEngine.hpp"
#include "ElectricCar.hpp"
#include "HybridCar.hpp"

class CarsTests : public ::testing::Test
{
protected:
    PetrolCar opel{std::make_unique<PetrolEngine>(PetrolEngine(120, 1800, 6))};
    ElectricCar nissan{std::make_unique<ElectricEngine>(ElectricEngine(130, 650))};
    HybridCar toyota{std::make_unique<PetrolEngine>(PetrolEngine(80, 1400, 5)), std::make_unique<ElectricEngine>(ElectricEngine(100, 540))};
};

//Electric car tests

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

//Petrol car tests

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

//Hybrid car tests

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

