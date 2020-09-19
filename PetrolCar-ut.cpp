#include "Car.hpp"
#include "Exceptions.hpp"
#include "PetrolCar.hpp"
#include "PetrolEngine.hpp"
#include "gtest/gtest.h"

constexpr int power = 120;
constexpr float capacity = 46.5;
constexpr int gears = 5;
constexpr int currentGear = 0;

class PetrolCarTest : public ::testing::Test {
protected:
    PetrolCarTest() : petrolCar(std::make_unique<PetrolEngine>(power, capacity, gears)){};

    PetrolCar petrolCar;
};

TEST_F(PetrolCarTest, PetrolCarCanAccelerate) {
    petrolCar.accelerate(50);
    ASSERT_EQ(petrolCar.getSpeed(), 50);
}

TEST_F(PetrolCarTest, PetrolCarCannotReachNegativeSpeed) {
    EXPECT_THROW(petrolCar.accelerate(-2), InvalidAcceleration);
}

TEST_F(PetrolCarTest, PetrolCannotChangeEngineDuringRide) {
    int newPower = 150;
    float newCapacity = 50.5;
    petrolCar.accelerate(50);
    EXPECT_THROW(petrolCar.changeEngine(std::make_unique<PetrolEngine>(newPower, newCapacity, gears)),
                 InvalidEngineChange);
}

TEST_F(PetrolCarTest, PetrolCanChangeGear) {
    petrolCar.setGear(1);
    ASSERT_EQ(petrolCar.getCurrentGear(), 1);
}

TEST_F(PetrolCarTest, PetrolCannotChangeGearToReverseFrom2) {
    petrolCar.setGear(2);
    EXPECT_THROW(petrolCar.setGear(-1), InvalidGear);
}

TEST_F(PetrolCarTest, PetrolCannotChangeTooManyGearsAtOnce) {
    EXPECT_THROW(petrolCar.setGear(5), InvalidGear);
}

TEST_F(PetrolCarTest, PetrolCannotBeInitializedWithNegativeCapacity) {
    int newCapacity = -750;
    EXPECT_THROW(petrolCar.changeEngine(std::make_unique<PetrolEngine>(power, newCapacity, gears)), InvalidParameter);
}

TEST_F(PetrolCarTest, PetrolCannotBeInitializedWithNegativeGearsNumber) {
    int newGears = -4;
    EXPECT_THROW(petrolCar.changeEngine(std::make_unique<PetrolEngine>(power, capacity, newGears)), InvalidParameter);
}

TEST_F(PetrolCarTest, PetrolCannotBeInitializedWithNegativePower) {
    int newPower = -50;
    EXPECT_THROW(petrolCar.changeEngine(std::make_unique<PetrolEngine>(newPower, capacity, gears)), InvalidParameter);
}
