#include "gtest/gtest.h"

#include "Car.hpp"
#include "ElectricEngine.hpp"
#include "Engine.hpp"
#include "HybridCar.hpp"
#include "PetrolEngine.hpp"

struct HybridCarTest : public ::testing::Test {
    int powerPetrol { 200 };
    float capacityPetrol { 3000};
    int gears { 6 };
    int powerElectric { 300};
    float capacityElectric { 1000};
    Car* car; 
    Engine* engineOne;
    Engine* engineTwo;
    PetrolEngine petrolEngine;
    ElectricEngine electricEngine;
    HybridCar hybridCar;
    HybridCarTest() 
        : petrolEngine(powerPetrol, capacityPetrol, gears)
        , electricEngine(powerElectric, capacityElectric)
        , engineOne(&electricEngine)
        , engineTwo(&petrolEngine)
        , hybridCar(engineOne, engineTwo)
        , car(&hybridCar)
    {}
};

TEST_F(HybridCarTest, callShouldReturnCorrectMaxSpeedElectric) {
    auto expected = 1000;
    auto result = engineOne->getMaxSpeed();
    ASSERT_EQ(result, expected);
}

TEST_F(HybridCarTest, callShouldReturnCorrectMaxSpeedPetrol) {
    auto expected = 1200;
    auto result = engineTwo->getMaxSpeed();
    ASSERT_EQ(result, expected);
}

TEST_F(HybridCarTest, callShouldReturnCorrectMaxReverseSpeedElectric) {
    auto expected = -200;
    auto result = engineOne->getMaxReverseSpeed();
    ASSERT_EQ(result, expected);
}

TEST_F(HybridCarTest, callShouldReturnCorrectMaxReverseSpeedPetrol) {
    auto expected = -200;
    auto result = engineTwo->getMaxReverseSpeed();
    ASSERT_EQ(result, expected);
}

TEST_F(HybridCarTest, callShouldReturnExceptionInvalidAccelerateMinus) {
    ASSERT_THROW(car->accelerate(-500), Car::InvalidAccelerate);
}

TEST_F(HybridCarTest, callShouldntReturnAnyExceptionMinus) {
    EXPECT_NO_THROW(car->accelerate(-122));
}

TEST_F(HybridCarTest, callShouldReturnExceptionInvalidAcceleratePlus) {
    ASSERT_THROW(car->accelerate(2222), Car::InvalidAccelerate);
}

TEST_F(HybridCarTest, callShouldntReturnAnyExceptionPlus) {
    EXPECT_NO_THROW(car->accelerate(999));
}

TEST_F(HybridCarTest, callShouldReturnExceptionInvalidGearUpPetrol) {
    ASSERT_THROW(hybridCar.changeGear(6, petrolEngine), PetrolEngine::InvalidGear);
}

TEST_F(HybridCarTest, callShouldReturnExceptionInvalidGearDownPetrol) {
    ASSERT_THROW(hybridCar.changeGear(-6, petrolEngine), PetrolEngine::InvalidGear);
}

TEST_F(HybridCarTest, callShouldntReturnAnyExceptionUpGearPetrol) {
    hybridCar.changeGear(1, petrolEngine);
    hybridCar.changeGear(2, petrolEngine);
    hybridCar.changeGear(3, petrolEngine);
    EXPECT_NO_THROW(hybridCar.changeGear(4, petrolEngine));
}

TEST_F(HybridCarTest, callShouldntReturnAnyExceptionDownGearPetrol) {
    EXPECT_NO_THROW(hybridCar.changeGear(-1, petrolEngine));
}
