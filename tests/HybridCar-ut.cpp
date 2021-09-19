#include <gtest/gtest.h>

#include <memory>
#include "Car.hpp"
#include "ElectricEngine.hpp"
#include "HybridCar.hpp"
#include "PetrolEngine.hpp"

struct HybridCarTests : public ::testing::Test {
    const int maxGear{7};
    HybridCar toyota{std::make_unique<PetrolEngine>(Engine::HorsePower(200),
                                                    PetrolEngine::CubicCentimetre(2000),
                                                    PetrolEngine::Gear(maxGear)),
                     std::make_unique<ElectricEngine>(Engine::HorsePower(100),
                                                      ElectricEngine::AmpereHour(540))};
    Car* car = &toyota;
};

TEST_F(HybridCarTests, shouldAccelerate) {
    car->accelerate(Car::Speed(200));
    ASSERT_EQ(car->getSpeed(), Car::Speed(200));
}

TEST_F(HybridCarTests, shouldNotAccelerateTooHigh) {
    car->accelerate(Car::Speed(201));
    ASSERT_EQ(car->getSpeed(), Car::Speed(0));
}

TEST_F(HybridCarTests, shouldNotAccelerateNegative) {
    car->accelerate(Car::Speed(-10));
    ASSERT_EQ(car->getSpeed(), Car::Speed(0));
}

TEST_F(HybridCarTests, shouldBrake) {
    car->accelerate(Car::Speed(100));
    ASSERT_EQ(car->getSpeed(), Car::Speed(100));
    car->brake();
    ASSERT_EQ(car->getSpeed(), Car::Speed(0));
}

TEST_F(HybridCarTests, shouldChangeEngine) {
    std::unique_ptr<PetrolEngine> newPetrolEngine{std::make_unique<PetrolEngine>(Engine::HorsePower(250),
                                                                                 PetrolEngine::CubicCentimetre(2500),
                                                                                 PetrolEngine::Gear(6))};
    ASSERT_NO_THROW(car->changeEngine(std::move(newPetrolEngine)));

    std::unique_ptr<ElectricEngine> newElectricEngine{std::make_unique<ElectricEngine>(Engine::HorsePower(100),
                                                                                       ElectricEngine::AmpereHour(600))};
    ASSERT_NO_THROW(car->changeEngine(std::move(newElectricEngine)));
}
