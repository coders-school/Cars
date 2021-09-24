#include "gtest/gtest.h"

#include "Car.hpp"
#include "ElectricCar.hpp"
#include "ElectricEngine.hpp"
#include "Engine.hpp"

struct ElectricCarTest : public ::testing::Test {
    int power { 200 };
    float capacity { 500 };
    Car* car; 
    Engine* engine;
    ElectricEngine electricEngine;
    ElectricCar electricCar;
    ElectricCarTest() 
        : electricEngine(power, capacity) 
        , engine(&electricEngine)
        , electricCar(engine)
        , car(&electricCar)
    {}
};

TEST_F(ElectricCarTest, callShouldReturnCorrectMaxSpeed) {
    auto expected = 333;
    auto result = engine->getMaxSpeed();
    ASSERT_EQ(result, expected);
}

TEST_F(ElectricCarTest, callShouldReturnCorrectMaxReverseSpeed) {
    auto expected = -66;
    auto result = engine->getMaxReverseSpeed();
    ASSERT_EQ(result, expected);
}

TEST_F(ElectricCarTest, callShouldReturnExceptionInvalidAccelerateMinus) {
    ASSERT_THROW(car->accelerate(-67), Car::InvalidAccelerate);
}

TEST_F(ElectricCarTest, callShouldntReturnAnyExceptionMinus) {
    EXPECT_NO_THROW(car->accelerate(-20));
}

TEST_F(ElectricCarTest, callShouldReturnExceptionInvalidAcceleratePlus) {
    ASSERT_THROW(car->accelerate(334), Car::InvalidAccelerate);
}

TEST_F(ElectricCarTest, callShouldntReturnAnyExceptionPlus) {
    EXPECT_NO_THROW(car->accelerate(333));
}

