#include <gtest/gtest.h>
#include "PetrolCar.hpp"


constexpr int enginePower = 100;
constexpr float engineCapacity = 8.0;
constexpr int engineGears = 6;

constexpr int betterEnginePower = 100;

TEST(PetrolCarTest, ChangingEngineDouringDrivingShouldThrowException){
    PetrolCar newCar(std::make_unique<PetrolEngine>(enginePower, engineCapacity, engineGears));
    newCar.accelerate(40);
    EXPECT_THROW(newCar.changeEngine(std::make_unique<PetrolEngine>(betterEnginePower, engineCapacity, engineGears)), InvalidEngineChange);
}


