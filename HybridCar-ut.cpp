#include<iostream>
#include "HybridCar.hpp"
#include "ElectricEngine.hpp"
#include <gtest/gtest.h>

class HybridCarTestFixture : public ::testing::Test {
 protected:
    HybridCar toyota{std::make_unique<PetrolEngine>(80, 1400, 5), std::make_unique<ElectricEngine>(100, 540)};
    void SetUp() override { toyota.reFill();};
};

TEST_F(HybridCarTestFixture, RefillTest)
{
    //Arrange
    
    //Act

    //Assert
    ASSERT_EQ(100, toyota.getCharge());
}

TEST_F(HybridCarTestFixture, AccelerationTest)
{
    //Arrange
    
    //Act
    toyota.accelerate(40);

    //Assert
    ASSERT_EQ(40, toyota.getSpeed());
}

TEST_F(HybridCarTestFixture,BrakeTest)
{
    //Arrange

    //Act
    toyota.accelerate(40);
    toyota.brake();

    //Assert
    ASSERT_EQ(0, toyota.getSpeed());
}

TEST_F(HybridCarTestFixture, InvalidSpeedTesT)
{
    //Arrange

    //Act

    //Assert
    EXPECT_THROW(toyota.accelerate(220), Car::InvalidSpeed);
}

TEST_F(HybridCarTestFixture,ChangeEngineTest1)
{
    //Arrange
    toyota.accelerate(60);
    
    //Act

    //Assert
    EXPECT_THROW(toyota.changeEngine(std::make_unique<ElectricEngine>(130, 650)), HybridCar::CarMoving);
}

TEST_F(HybridCarTestFixture,ChangeEngineTest2)
{
    //Arrange
    toyota.accelerate(60);
    
    //Act

    //Assert
    EXPECT_THROW(toyota.changeEngine(std::make_unique<PetrolEngine>(90, 1600, 6)), HybridCar::CarMoving);
}