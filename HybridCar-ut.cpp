#include <gtest/gtest.h>

#include "Exception.hpp"
#include "HybridCar.hpp"

constexpr int power = 200;
constexpr float batteryCap = 50.f;
constexpr float capacity = 50.f;
constexpr int gears = 5;
constexpr int rearGear = -1;

constexpr int expectedSpeed = 100;
constexpr int invalidValue = 42;
constexpr int modifier = 1;

struct HybridCarTest : public ::testing::Test {
    std::unique_ptr<PetrolEngine> petrolEngine = std::make_unique<PetrolEngine>(power, capacity, gears);
    std::unique_ptr<ElectricEngine> electricEngine = std::make_unique<ElectricEngine>(power, batteryCap);
    HybridCar car{std::move(petrolEngine), std::move(electricEngine)};
};

TEST_F(HybridCarTest, shouldAccelerate) {
    car.accelerate(expectedSpeed);
    ASSERT_EQ(car.getSpeed(), expectedSpeed);
}

TEST_F(HybridCarTest, shouldBrake) {
    car.brake();
    ASSERT_EQ(car.getSpeed(), noSpeed);
}

TEST_F(HybridCarTest, shouldThrowAccelerateException) {
    ASSERT_THROW(car.accelerate(-expectedSpeed), InvalidAcceleration);
}

TEST_F(HybridCarTest, shouldThrowExceptionWhenChangingToInvalidGear) {
    ASSERT_THROW(car.getPetrolEngine()->changeGear(invalidValue), InvalidGear);
    ASSERT_THROW(car.getPetrolEngine()->changeGear(-invalidValue), InvalidGear);
}

TEST_F(HybridCarTest, shouldChangeGearAndThrowExceptionWhenChangingFrom5ToRear) {
    car.getPetrolEngine()->changeGear(gears);
    ASSERT_EQ(car.getPetrolEngine()->getCurrentGear(), gears);
    ASSERT_THROW(car.getPetrolEngine()->changeGear(rearGear), InvalidGear);
}

TEST_F(HybridCarTest, shouldChangePetrolEngine) {
    auto currEngine = car.getPetrolEngine();
    auto newEngine = std::make_unique<PetrolEngine>(power + modifier, capacity + modifier, gears + modifier);
    car.brake();
    car.changeEngine(std::move(newEngine));
    ASSERT_NE(currEngine->getPower(), car.getPetrolEngine()->getPower());
    ASSERT_NE(currEngine->getCapacity(), car.getPetrolEngine()->getCapacity());
    ASSERT_NE(currEngine->getGears(), car.getPetrolEngine()->getGears());
}

TEST_F(HybridCarTest, shoudlChangeElectricEngine) {
    auto currEngine = car.getElectricEngine();
    auto newEngine = std::make_unique<ElectricEngine>(power + modifier, batteryCap + modifier);
    car.brake();
    car.changeEngine(std::move(newEngine));
    ASSERT_NE(currEngine->getPower(), car.getElectricEngine()->getPower());
    ASSERT_NE(currEngine->getBatteryCap(), car.getElectricEngine()->getBatteryCap());
}

TEST_F(HybridCarTest, shoudlThrowExceptionWhenChangingEngineWhileSpeedAbove0) {
    car.accelerate(expectedSpeed);
    ASSERT_THROW(car.changeEngine(std::make_unique<ElectricEngine>(power + modifier, batteryCap + modifier)), InvalidEngineChange);
    ASSERT_THROW(car.changeEngine(std::make_unique<PetrolEngine>(power + modifier, capacity + modifier, gears + modifier)), InvalidEngineChange);
}
