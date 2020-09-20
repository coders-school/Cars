#include "ExceptionsCars.hpp"
#include "PetrolCar.hpp"
#include "PetrolEngine.hpp"
#include "gtest/gtest.h"

struct PetrolCarTest : ::testing::Test {
    PetrolCar petrolCar = PetrolCar(new PetrolEngine(120, 1800, 6));
    PetrolCar petrolCar2 = PetrolCar(new PetrolEngine(120, 1800, 5));
};

TEST_F(PetrolCarTest, ShouldNotThrowExceptionWhenChangeGearByOne)
{
    EXPECT_NO_THROW(petrolCar.changeGear(GearBox::first));
    EXPECT_NO_THROW(petrolCar.changeGear(GearBox::second));
    EXPECT_NO_THROW(petrolCar.changeGear(GearBox::third));
    EXPECT_NO_THROW(petrolCar.changeGear(GearBox::second));
    EXPECT_NO_THROW(petrolCar.changeGear(GearBox::first));
    EXPECT_NO_THROW(petrolCar.changeGear(GearBox::neutral));
    EXPECT_NO_THROW(petrolCar.changeGear(GearBox::rear));
    
}

TEST_F(PetrolCarTest, ShouldThrowInvalidGearWhenTryToChangeGearByTwoOrMore)
{
    EXPECT_NO_THROW(petrolCar.changeGear(GearBox::first));
    EXPECT_NO_THROW(petrolCar.changeGear(GearBox::second));
    EXPECT_NO_THROW(petrolCar.changeGear(GearBox::third));
    EXPECT_THROW(petrolCar.changeGear(GearBox::rear), InvalidGear);
}

TEST_F(PetrolCarTest, ShouldThrowInvalidGearWhenTryToChangeGearWhichNotExists)
{
    EXPECT_NO_THROW(petrolCar2.changeGear(GearBox::first));
    EXPECT_NO_THROW(petrolCar2.changeGear(GearBox::second));
    EXPECT_NO_THROW(petrolCar2.changeGear(GearBox::third));
    EXPECT_NO_THROW(petrolCar2.changeGear(GearBox::fourth));
    EXPECT_NO_THROW(petrolCar2.changeGear(GearBox::fifth));
    EXPECT_THROW(petrolCar2.changeGear(GearBox::sixth), InvalidGear);
}

TEST_F(PetrolCarTest, ShouldNotThrowInvalidAccelerateWhenTryToAccelerateWithPositiveNumber)
{
    EXPECT_NO_THROW(petrolCar.accelerate(50));
    EXPECT_NO_THROW(petrolCar.accelerate(40));
    EXPECT_NO_THROW(petrolCar.accelerate(900));
    EXPECT_NO_THROW(petrolCar.accelerate(4.4));
    EXPECT_NO_THROW(petrolCar.accelerate(444.9));
}

TEST_F(PetrolCarTest, ShouldThrowInvalidAccelerateWhenTryToAccelerateWithNegativeNumber)
{
    EXPECT_THROW(petrolCar.accelerate(-500), InvalidAccelerate);
    EXPECT_THROW(petrolCar.accelerate(-115.10), InvalidAccelerate);
    EXPECT_THROW(petrolCar2.accelerate(-54.0), InvalidAccelerate);
    EXPECT_THROW(petrolCar2.accelerate(-5.40), InvalidAccelerate);
}

