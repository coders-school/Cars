#include "gtest/gtest.h"

#include "Car.hpp"
#include "Engine.hpp"
#include "PetrolCar.hpp"
#include "PetrolEngine.hpp"

struct PetrolCarTest : public ::testing::Test {
    int power { 100 };
    float capacity { 2000 };
    int gears { 5 };
    Car* car; 
    Engine* engine;
    PetrolEngine petrolEngine;
    PetrolCar petrolCar;
    PetrolCarTest() 
        : petrolEngine(power, capacity, gears) 
        , engine(&petrolEngine)
        , petrolCar(engine)
        , car(&petrolCar)
    {}
};

TEST_F(PetrolCarTest, callShouldReturnCorrectMaxSpeed) {
    auto expected = 400;
    auto result = engine->getMaxSpeed();
    ASSERT_EQ(result, expected);
}

TEST_F(PetrolCarTest, callShouldReturnCorrectMaxReverseSpeed) {
    auto expected = -66;
    auto result = engine->getMaxReverseSpeed();
    ASSERT_EQ(result, expected);
}

TEST_F(PetrolCarTest, callShouldReturnExceptionInvalidAccelerateMinus) {
    ASSERT_THROW(car->accelerate(-900), Car::InvalidAccelerate);
}

TEST_F(PetrolCarTest, callShouldntReturnAnyExceptionMinus) {
    EXPECT_NO_THROW(car->accelerate(-40));
}

TEST_F(PetrolCarTest, callShouldReturnExceptionInvalidAcceleratePlus) {
    ASSERT_THROW(car->accelerate(4000), Car::InvalidAccelerate);
}

TEST_F(PetrolCarTest, callShouldntReturnAnyExceptionPlus) {
    EXPECT_NO_THROW(car->accelerate(200));
}

TEST_F(PetrolCarTest, callShouldReturnExceptionInvalidGearUp) {
    ASSERT_THROW(petrolCar.changeGear(6, petrolEngine), PetrolEngine::InvalidGear);
}

TEST_F(PetrolCarTest, callShouldReturnExceptionInvalidGearDown) {
    ASSERT_THROW(petrolCar.changeGear(-6, petrolEngine), PetrolEngine::InvalidGear);
}

TEST_F(PetrolCarTest, callShouldntReturnAnyExceptionUpGear) {
    petrolCar.changeGear(1, petrolEngine);
    petrolCar.changeGear(2, petrolEngine);
    petrolCar.changeGear(3, petrolEngine);
    EXPECT_NO_THROW(petrolCar.changeGear(4, petrolEngine));
}

TEST_F(PetrolCarTest, callShouldntReturnAnyExceptionDownGear) {
    EXPECT_NO_THROW(petrolCar.changeGear(-1, petrolEngine));
}
