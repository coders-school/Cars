#include <gtest/gtest.h>
#include <memory>

#include "Car.hpp"
#include "Exception.hpp"
#include "ElectricCar.hpp"
#include "ElectricEngine.hpp"

constexpr int power = 200;
constexpr float batteryCap = 50.f;

constexpr int expectedSpeed = 100;
constexpr int invalidValue = 42;
constexpr int modifier = 1;

struct ElectricCarTest : public ::testing::Test {
    ElectricCar car{std::make_unique<ElectricEngine>(power, batteryCap)};
};

TEST_F(ElectricCarTest, shouldAccelerate) {
    car.accelerate(expectedSpeed);
    ASSERT_EQ(car.getSpeed(), expectedSpeed);
}

TEST_F(ElectricCarTest, shouldBrake) {
    car.brake();
    ASSERT_EQ(car.getSpeed(), 0);
}

TEST_F(ElectricCarTest, shouldThrowAccelerateException) {
    ASSERT_THROW(car.accelerate(-expectedSpeed), InvalidAcceleration);
}

TEST_F(ElectricCarTest, shoudlChangeEngine) {
    auto currEngine = car.getEngine();
    auto newEngine = std::make_unique<ElectricEngine>(power + modifier, batteryCap + modifier);
    car.brake();
    car.changeEngine(std::move(newEngine));
    ASSERT_NE(currEngine->getPower(), car.getEngine()->getPower());
    ASSERT_NE(currEngine->getBatteryCap(), car.getEngine()->getBatteryCap());
}

TEST_F(ElectricCarTest, shoudlThrowExceptionWhenChangingEngineWhileSpeedAbove0) {
    car.accelerate(expectedSpeed);
    ASSERT_THROW(car.changeEngine(std::make_unique<ElectricEngine>(power + modifier, batteryCap + modifier)), InvalidEngineChange);
}
