#include <gtest/gtest.h>
#include "PetrolCar.hpp"

constexpr int enginePower = 100;
constexpr float engineCapacity = 8.0;
constexpr int engineGears = 6;

constexpr int betterEnginePower = 150;

class PetrolCarTest : public testing::Test {
public:
    PetrolCarTest()
        : car(std::make_unique<PetrolEngine>(enginePower, engineCapacity, engineGears)) {}
    PetrolCar car;
};
TEST_F(PetrolCarTest, ChangingEngineDouringDrivingShouldThrowException) {
    car.accelerate(40);
    EXPECT_THROW(car.changeEngine(std::make_unique<PetrolEngine>(betterEnginePower, engineCapacity, engineGears)), InvalidEngineChange);
}

TEST_F(PetrolCarTest, IfSpeedHigherThanBrakePowerSpeedShouldBeReduceByBrakePower) {
    car.accelerate(50);
    car.brake(30);
    EXPECT_EQ(car.getSpeed(), 20);
}

TEST_F(PetrolCarTest, IfSpeedLowerThanBrakePowerSpeedShouldBeEqualToZero) {
    car.accelerate(70);
    car.brake(90);
    EXPECT_EQ(car.getSpeed(), 0);
}

TEST_F(PetrolCarTest, IfCarStayChangeEngineShouldBeCorrect){
    car.accelerate(50);
    car.brake(51);
    car.changeEngine(std::make_unique<PetrolEngine>(betterEnginePower, engineCapacity, engineGears));
    EXPECT_EQ(car.getPetrolEnginePower(), betterEnginePower);
}
