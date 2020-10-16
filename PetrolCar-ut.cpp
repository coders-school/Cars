#include <gtest/gtest.h>
#include <memory>

#include "Car.hpp"
#include "Exception.hpp"
#include "PetrolCar.hpp"
#include "PetrolEngine.hpp"

constexpr int power = 200;
constexpr float capacity = 50.f;
constexpr int gears = 5;
constexpr int rearGear = -1;

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
    ASSERT_EQ(car.getSpeed(), noSpeed);
}

TEST_F(PetrolCarTest, shouldThrowAccelerateException) {
    ASSERT_THROW(car.accelerate(-expectedSpeed), InvalidAcceleration);
}

TEST_F(PetrolCarTest, shouldThrowExceptionWhenChangingToInvalidGear) {
    ASSERT_THROW(car.getEngine()->changeGear(invalidValue), InvalidGear);
    ASSERT_THROW(car.getEngine()->changeGear(-invalidValue), InvalidGear);
}

TEST_F(PetrolCarTest, shouldChangeGearAndThrowExceptionWhenChangingFrom5ToRear) {
    car.getEngine()->changeGear(gears);
    ASSERT_EQ(car.getEngine()->getCurrentGear(), gears);
    ASSERT_THROW(car.getEngine()->changeGear(rearGear), InvalidGear);
}

TEST_F(PetrolCarTest, shouldChangeEngine) {
    auto currEngine = car.getEngine();
    auto newEngine = std::make_unique<PetrolEngine>(power + modifier, capacity + modifier, gears + modifier);
    car.brake();
    car.changeEngine(std::move(newEngine));
    ASSERT_NE(currEngine->getPower(), car.getEngine()->getPower());
    ASSERT_NE(currEngine->getCapacity(), car.getEngine()->getCapacity());
    ASSERT_NE(currEngine->getGears(), car.getEngine()->getGears());
}

TEST_F(PetrolCarTest, shoudlThrowExceptionWhenChangingEngineWhileSpeedAbove0) {
    car.accelerate(expectedSpeed);
    ASSERT_THROW(car.changeEngine(std::make_unique<PetrolEngine>(power - modifier, capacity - modifier, gears - modifier)), InvalidEngineChange);
}
