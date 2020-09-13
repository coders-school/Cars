#include <gtest/gtest.h>
#include "ElectricCar.hpp"
#include "ElectricEngine.hpp"

struct ElectricCarTest : public ::testing::Test {
    // GIVEN
    ElectricCar nissan = ElectricCar(std::make_unique<ElectricEngine>(213, 125));
};

TEST_F(ElectricCarTest, shouldAccelerate)
{
    // WHEN
    nissan.accelerate(15);

    // THEN
    EXPECT_EQ(nissan.getSpeed(), 15);
}

TEST_F(ElectricCarTest, shouldNotAccelerate)
{
    // WHEN
    nissan.accelerate(24);
    nissan.accelerate(-12);

    // THEN
    EXPECT_EQ(nissan.getSpeed(), 24);
}