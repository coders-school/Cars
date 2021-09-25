#include "gtest/gtest.h"

#include <memory>
#include <utility>

#include "../Car.hpp"
#include "../ElectricCar.hpp"
#include "../ElectricEngine.hpp"
#include "../Exeptions.hpp"
#include "../PetrolEngine.hpp"

struct ElectricCarTest : public ::testing::Test {
    int power_{100};
    int capacity_{700};
    ElectricCar electricCar = std::make_unique<ElectricEngine>(power_, capacity_);
    Car* car = &electricCar;
};

TEST_F(ElectricCarTest, ShouldRAccelerate) {
    car->accelerate(120);
    ASSERT_EQ(car->getSpeed(), 120);
}

TEST_F(ElectricCarTest, ShouldThrowExeptionTooHighSpeed) {
    EXPECT_THROW(car->accelerate(200);, InvalidParameter);
}

TEST_F(ElectricCarTest, ShouldThrowExeptionTooLowSpeed) {
    ASSERT_THROW(car->accelerate(-10);, InvalidParameter);
}

TEST_F(ElectricCarTest, ShouldBreak) {
    car->accelerate(150);
    ASSERT_EQ(car->getSpeed(), 150);
    car->brake();
    ASSERT_EQ(car->getSpeed(), 0);
}

TEST_F(ElectricCarTest, ShouldChangeEngine) {
    std::unique_ptr<ElectricEngine> newEngine{std::make_unique<ElectricEngine>(120, 200)};
    EXPECT_NO_THROW(car->changeEngine(std::move(newEngine)));
}

TEST_F(ElectricCarTest, ShouldNotChangeEngine) {
    std::unique_ptr<PetrolEngine> newEngine{std::make_unique<PetrolEngine>(88, 200.1, 8)};
    EXPECT_THROW(car->changeEngine(std::move(newEngine)), InvalidParameter);
}
