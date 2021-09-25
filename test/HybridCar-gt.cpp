#include "gtest/gtest.h"

#include <memory>
#include <stdexcept>
#include <utility>

#include "../Car.hpp"
#include "../ElectricEngine.hpp"
#include "../Exeptions.hpp"
#include "../HybridCar.hpp"
#include "../PetrolEngine.hpp"

struct HybridCarTest : public ::testing::Test {
    HybridCar hybridCar{std::make_unique<PetrolEngine>(100, 1200, 6), std::make_unique<ElectricEngine>(100, 1200)};
    Car* car = &hybridCar;
};

TEST_F(HybridCarTest, ShouldRAccelerate) {
    car->accelerate(120);
    ASSERT_EQ(car->getSpeed(), 120);
}

TEST_F(HybridCarTest, ShouldThrowExeptionTooHighSpeed) {
    EXPECT_THROW(car->accelerate(200), InvalidParameter);
}

TEST_F(HybridCarTest, ShouldThrowExeptionTooLowSpeed) {
    ASSERT_THROW(car->accelerate(-10);, InvalidParameter);
}

TEST_F(HybridCarTest, ShouldBreak) {
    car->accelerate(150);
    ASSERT_EQ(car->getSpeed(), 150);
    car->brake();
    ASSERT_EQ(car->getSpeed(), 0);
}

TEST_F(HybridCarTest, ShouldChangeEngine) {
    std::unique_ptr<ElectricEngine> newEngine{std::make_unique<ElectricEngine>(120, 200)};
    EXPECT_NO_THROW(car->changeEngine(std::move(newEngine)));
}

TEST_F(HybridCarTest, ShouldNotChangeEngine) {
    std::unique_ptr<PetrolEngine> newEngine{std::make_unique<PetrolEngine>(88, 200.1, 8)};
    EXPECT_NO_THROW(car->changeEngine(std::move(newEngine)));
}