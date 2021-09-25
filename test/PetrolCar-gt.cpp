#include "gtest/gtest.h"

#include <memory>
#include <stdexcept>
#include <utility>

#include "../Car.hpp"
#include "../ElectricEngine.hpp"
#include "../Exeptions.hpp"
#include "../PetrolCar.hpp"
#include "../PetrolEngine.hpp"

struct PetrolCarTest : public ::testing::Test {
    PetrolCar petrolCar{std::make_unique<PetrolEngine>(100, 2000, 6)};
    Car* car = &petrolCar;
};

TEST_F(PetrolCarTest, ShouldAccelerate) {
    car->accelerate(120);
    EXPECT_EQ(car->getSpeed(), 120);
}

TEST_F(PetrolCarTest, ShouldThrowExeptionTooHighSpeed) {
    EXPECT_THROW(car->accelerate(200);, InvalidParameter);
}

TEST_F(PetrolCarTest, ShouldThrowExeptionTooLowSpeed) {
    ASSERT_THROW(car->accelerate(-10);, InvalidParameter);
}

TEST_F(PetrolCarTest, ShouldBreak) {
    car->accelerate(150);
    ASSERT_EQ(car->getSpeed(), 150);
    car->brake();
    ASSERT_EQ(car->getSpeed(), 0);
}

TEST_F(PetrolCarTest, ShouldChangeEngine) {
    std::unique_ptr<PetrolEngine> newEngine{std::make_unique<PetrolEngine>(120, 2000, 6)};
    EXPECT_NO_THROW(car->changeEngine(std::move(newEngine)));
}

TEST_F(PetrolCarTest, ShouldNotChangeEngine) {
    std::unique_ptr<ElectricEngine> newEngine{std::make_unique<ElectricEngine>(88, 2000)};
    EXPECT_THROW(car->changeEngine(std::move(newEngine)), InvalidParameter);
}

TEST_F(PetrolCarTest, ShouldNoThrowGearExeption) {
    PetrolEngine* engine = petrolCar.getEngine();
    for (int i = 0; i <= engine->getGears(); i++) {
        EXPECT_NO_THROW(engine->changeGear(i));
    }
    for (int i = engine->getGears(); i >= 0; i--) {
        EXPECT_NO_THROW(engine->changeGear(i));
    }
    EXPECT_NO_THROW(engine->changeGear(-1));
}

TEST_F(PetrolCarTest, UseGearBoxUnsaftly) {
    PetrolEngine* engine = petrolCar.getEngine();
    engine->changeGear(5);
    EXPECT_THROW(engine->changeGear(-1), InvalidGear);
}