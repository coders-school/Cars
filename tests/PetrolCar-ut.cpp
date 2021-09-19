#include <gtest/gtest.h>

#include <memory>
#include "Car.hpp"
#include "ElectricEngine.hpp"
#include "MyExceptions.hpp"
#include "PetrolCar.hpp"
#include "PetrolEngine.hpp"

struct PetrolCarTests : public ::testing::Test {
    const int maxGear{7};
    PetrolCar opel{std::make_unique<PetrolEngine>(Engine::HorsePower(200),
                                                  PetrolEngine::CubicCentimetre(2000),
                                                  PetrolEngine::Gear(maxGear))};
    Car* car = &opel;
};

TEST_F(PetrolCarTests, shouldAccelerate) {
    car->accelerate(Car::Speed(200));
    ASSERT_EQ(car->getSpeed(), Car::Speed(200));
}

TEST_F(PetrolCarTests, shouldNotAccelerateTooHigh) {
    car->accelerate(Car::Speed(201));
    ASSERT_EQ(car->getSpeed(), Car::Speed(0));
}

TEST_F(PetrolCarTests, shouldNotAccelerateNegative) {
    car->accelerate(Car::Speed(-10));
    ASSERT_EQ(car->getSpeed(), Car::Speed(0));
}

TEST_F(PetrolCarTests, shouldBrake) {
    car->accelerate(Car::Speed(100));
    ASSERT_EQ(car->getSpeed(), Car::Speed(100));
    car->brake();
    ASSERT_EQ(car->getSpeed(), Car::Speed(0));
}

TEST_F(PetrolCarTests, shouldChangeEngine) {
    std::unique_ptr<PetrolEngine> newEngine{std::make_unique<PetrolEngine>(Engine::HorsePower(250),
                                                                           PetrolEngine::CubicCentimetre(2500),
                                                                           PetrolEngine::Gear(6))};
    ASSERT_NO_THROW(car->changeEngine(std::move(newEngine)));
}

TEST_F(PetrolCarTests, shouldNotChangeEngine) {
    std::unique_ptr<ElectricEngine> newEngine{std::make_unique<ElectricEngine>(Engine::HorsePower(100),
                                                                               ElectricEngine::AmpereHour(600))};
    ASSERT_THROW(car->changeEngine(std::move(newEngine)), InvalidEngine);
}

TEST_F(PetrolCarTests, shouldChangeGear) {
    PetrolEngine* engine = opel.getEngine();
    for (int i = 0; i <= maxGear; ++i) {
        ASSERT_NO_THROW(engine->changeGear(PetrolEngine::Gear(i)));
    }
    for (int i = maxGear; i >= 0; --i) {
        ASSERT_NO_THROW(engine->changeGear(PetrolEngine::Gear(i)));
    }
    ASSERT_NO_THROW(engine->changeGear(PetrolEngine::Gear(-1)));
}

TEST_F(PetrolCarTests, shouldNotChangeGearInvalidGear) {
    PetrolEngine* engine = opel.getEngine();
    ASSERT_THROW(engine->changeGear(PetrolEngine::Gear(-2)), InvalidGear);
    ASSERT_THROW(engine->changeGear(PetrolEngine::Gear(maxGear + 1)), InvalidGear);
}

TEST_F(PetrolCarTests, shouldNotChangeGearUnsafe) {
    PetrolEngine* engine = opel.getEngine();
    engine->changeGear(PetrolEngine::Gear(1));
    car->accelerate(Car::Speed(10));
    ASSERT_THROW(engine->changeGear(PetrolEngine::Gear(-1)), InvalidGear);
    car->brake();
    engine->changeGear(PetrolEngine::Gear(-1));
    car->accelerate(Car::Speed(10));
    ASSERT_THROW(engine->changeGear(PetrolEngine::Gear(1)), InvalidGear);
}
