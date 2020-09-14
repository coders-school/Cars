#include <gtest/gtest.h>
#include "ElectricCar.hpp"
#include "ElectricEngine.hpp"
#include "PetrolCar.hpp"
#include "PetrolEngine.hpp"
#include "HybridCar.hpp"
#include <functional>

PetrolCar ford{std::make_unique<PetrolEngine>(143, 2.653, 6)};
HybridCar toyota = HybridCar(std::make_unique<PetrolEngine>(112, 1.637, 5), std::make_unique<ElectricEngine>(135, 237));
ElectricCar nissan{std::make_unique<ElectricEngine>(213, 125)};

struct CarsTest : public ::testing::TestWithParam<Car*> {
};

TEST_P(CarsTest, shouldAccelerate)
{
    // GIWEN
    auto car = GetParam();

    // WHEN
    car->accelerate(15);

    // THEN
    EXPECT_EQ(car->getSpeed(), 15);
}

TEST_P(CarsTest, shouldNotAccelerate)
{
    // GIWEN
    auto car = GetParam();

    // WHEN
    car->accelerate(24);
    car->accelerate(-12);

    // THEN
    EXPECT_EQ(car->getSpeed(), 24);
}

INSTANTIATE_TEST_SUITE_P(SomeCars,
                         CarsTest,
                         ::testing::Values(&nissan, &ford, &toyota));
