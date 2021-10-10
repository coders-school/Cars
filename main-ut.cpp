#include<iostream>
#include "ElectricCar.hpp"
#include "PetrolCar.hpp"
#include "PetrolEngine.hpp"
#include "HybridCar.hpp"
#include <gtest/gtest.h>

class PetrolCarTestFixture : public ::testing::Test {
 protected:
    PetrolCar opel{new PetrolEngine(120, 1800, 6)};
};

TEST_F(PetrolCarTestFixture, AccelerationTest)
{
    //Arrange
    
    //Act
    opel.accelerate(40);

    //Assert
    ASSERT_EQ(40, opel.getSpeed());
}

TEST_F(PetrolCarTestFixture,BrakeTest)
{
    //Arrange

    //Act
    opel.accelerate(40);
    opel.brake();

    //Assert
    ASSERT_EQ(0, opel.getSpeed());
}

TEST_F(PetrolCarTestFixture, InvalidSpeedTesT)
{
    //Arrange

    //Act

    //Assert
    EXPECT_THROW(opel.accelerate(220), Car::InvalidSpeed);
}


TEST_F(PetrolCarTestFixture,GearChangeTest)
{
    //Arrange

    //Act
    opel.getEngine()->changeGear(1);

    //Assert
    ASSERT_EQ(1, opel.getEngine()->getCurrentGear());
}

TEST_F(PetrolCarTestFixture,InvalidGearTest)
{
    //Arrange
    opel.getEngine()->changeGear(5);
    
    //Act

    //Assert
    EXPECT_THROW(opel.getEngine()->changeGear(-1), PetrolEngine::InvalidGear);
}