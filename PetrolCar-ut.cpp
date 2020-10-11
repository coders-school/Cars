#include <gtest/gtest.h>
#include <memory>

#include "Car.hpp"
#include "Exception.hpp"
#include "PetrolCar.hpp"
#include "PetrolEngine.hpp"

constexpr int power = 200;
constexpr float capacity = 50.f;
constexpr int gears = 5;

constexpr int expectedSpeed = 100;
constexpr int invalidValue = 42;
constexpr int modifier = 1;

struct PetrolCarTest : public ::testing::Test {
    PetrolCar car{std::make_unique<PetrolEngine>(power, capacity, gears)};
};

TEST_F(PetrolCarTest, shouldAccelerate) {
    car.accelerate(expectedSpeed);
    ASSERT_EQ(car.getSpeed(), expectedSpeed);
}

TEST_F(PetrolCarTest, shouldBrake) {
    car.brake();
    ASSERT_EQ(car.getSpeed(), 0);
}

TEST_F(PetrolCarTest, shouldThrowAccelerateException) {
    ASSERT_THROW(car.accelerate(-expectedSpeed), InvalidAcceleration);
}

TEST_F(PetrolCarTest, shouldThrowExceptionWhenChangingToInvalidGear) {
    ASSERT_THROW(car.getEngine()->changeGear(invalidValue), InvalidGear);
    ASSERT_THROW(car.getEngine()->changeGear(-invalidValue), InvalidGear);
}

TEST_F(PetrolCarTest, shouldChangeGearAndThrowExceptionWhenChangingFrom5ToRear) {
    car.getEngine()->changeGear(5);
    ASSERT_EQ(car.getEngine()->getCurrentGear(), 5);
    ASSERT_THROW(car.getEngine()->changeGear(-1), InvalidGear);
}

TEST_F(PetrolCarTest, shouldChangeEngineAndThrowExceptionWhenSpeedAbove0) {
    car.brake();
    ASSERT_NO_THROW(car.changeEngine(std::make_unique<PetrolEngine>(power + modifier, capacity + modifier, gears + modifier)));
    car.accelerate(expectedSpeed);
    ASSERT_THROW(car.changeEngine(std::make_unique<PetrolEngine>(power - modifier, capacity - modifier, gears - modifier)), InvalidEngineChange);
}
