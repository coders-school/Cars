#include<iostream>
#include "ElectricCar.hpp"
#include "ElectricEngine.hpp"
#include <gtest/gtest.h>

class ElectricCarTestFixture : public ::testing::Test {
 protected:
    ElectricCar nissan{std::make_unique<ElectricEngine>(130, 650)};
    void SetUp() override { nissan.reFill();};
};

TEST_F(ElectricCarTestFixture, RefillTest)
{
    //Arrange
    
    //Act

    //Assert
    ASSERT_EQ(100, nissan.getCharge());
}

TEST_F(ElectricCarTestFixture, AccelerationTest)
{
    //Arrange
    
    //Act
    nissan.accelerate(40);

    //Assert
    ASSERT_EQ(40, nissan.getSpeed());
}

TEST_F(ElectricCarTestFixture,BrakeTest)
{
    //Arrange

    //Act
    nissan.accelerate(40);
    nissan.brake();

    //Assert
    ASSERT_EQ(0, nissan.getSpeed());
}

TEST_F(ElectricCarTestFixture, InvalidSpeedTesT)
{
    //Arrange

    //Act

    //Assert
    EXPECT_THROW(nissan.accelerate(220), Car::InvalidSpeed);
}

TEST_F(ElectricCarTestFixture,ChangeEngineTest)
{
    //Arrange
    nissan.accelerate(60);
    
    //Act

    //Assert
    EXPECT_THROW(nissan.changeEngine(std::make_unique<ElectricEngine>(130, 650)), ElectricCar::CarMoving);
}

