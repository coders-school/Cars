#include <gtest/gtest.h>

#include <memory>
#include "Car.hpp"
#include "ElectricCar.hpp"
#include "ElectricEngine.hpp"
#include "MyExceptions.hpp"
#include "PetrolEngine.hpp"

struct BasicElectricCarTests : public ::testing::Test {
    ElectricCar tesla{std::make_unique<ElectricEngine>(Engine::HorsePower(200), ElectricEngine::AmpereHour(500))};
    Car* car = &tesla;
};

TEST_F(BasicElectricCarTests, shouldAccelerate) {
    car->accelerate(Car::Speed(200));
    ASSERT_EQ(car->getSpeed(), Car::Speed(200));
}

TEST_F(BasicElectricCarTests, shouldNotAccelerateTooHigh) {
    car->accelerate(Car::Speed(201));
    ASSERT_EQ(car->getSpeed(), Car::Speed(0));
}

TEST_F(BasicElectricCarTests, shouldNotAccelerateNegative) {
    car->accelerate(Car::Speed(-10));
    ASSERT_EQ(car->getSpeed(), Car::Speed(0));
}

TEST_F(BasicElectricCarTests, shouldBrake) {
    car->accelerate(Car::Speed(100));
    ASSERT_EQ(car->getSpeed(), Car::Speed(100));
    car->brake();
    ASSERT_EQ(car->getSpeed(), Car::Speed(0));
}

TEST_F(BasicElectricCarTests, shouldChangeEngine) {
    std::unique_ptr<ElectricEngine> newEngine{std::make_unique<ElectricEngine>(Engine::HorsePower(100),
                                                                               ElectricEngine::AmpereHour(600))};
    ASSERT_NO_THROW(car->changeEngine(std::move(newEngine)));
}

TEST_F(BasicElectricCarTests, shouldNotChangeEngine) {
    std::unique_ptr<PetrolEngine> newEngine{std::make_unique<PetrolEngine>(Engine::HorsePower(250),
                                                                           PetrolEngine::CubicCentimetre(2500),
                                                                           PetrolEngine::Gear(6))};
    ASSERT_THROW(car->changeEngine(std::move(newEngine)), InvalidEngine);
}
