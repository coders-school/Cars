#include <iostream>
#include "PetrolCar.hpp"
#include "PetrolEngine.hpp"
#include <gtest/gtest.h>

class PetrolCarTestFixture : public ::testing::Test {
 protected:
    PetrolCar opel{std::make_unique<PetrolEngine>(120, 1800, 6)};
    void SetUp() override { opel.reFill();};
};

TEST_F(PetrolCarTestFixture, RefillTest)
{
    //Arrange
    
    //Act

    //Assert
    ASSERT_EQ(100, opel.getFuel());
}

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

TEST_F(PetrolCarTestFixture,ChangeEngineTest)
{
    //Arrange
    opel.accelerate(60);
    
    //Act

    //Assert
    EXPECT_THROW(opel.changeEngine(std::make_unique<PetrolEngine>(105, 1600, 5)), PetrolCar::CarMoving);
}
