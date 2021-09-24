#include "gtest/gtest.h"

#include "Car.hpp"
#include "ElectricCar.hpp"
#include "ElectricEngine.hpp"
#include "Engine.hpp"
#include "HybridCar.hpp"
#include "PetrolCar.hpp"
#include "PetrolEngine.hpp"

struct PetrolCarTest : public ::testing::Test {
    int power { 0 };
    float capacity { 0 };
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

TEST_F(PetrolCarTest, callMeShouldAlwaysReturn42) {
    // GIVEN
    auto expected = 42;

    // WHEN
   // auto result = cut.callMe();

    // THEN
    //ASSERT_EQ(result, expected);
}