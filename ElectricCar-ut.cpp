#include <gtest/gtest.h>
#include <memory>
#include "Car.hpp"
#include "ElectricCar.hpp"
#include "ElectricEngine.hpp"
#include "InvalidsError.hpp"

constexpr int power = 200;
constexpr float capacity = 140;

class ElectricCarTest : public ::testing::Test {
protected:
    ElectricCar electricCarTest{std::make_unique<ElectricEngine>(power, capacity)};
};

TEST_F(ElectricCarTest, TestOfAccelerate) {
    electricCarTest.accelerate(70);
    ASSERT_EQ(electricCarTest.getSpeed(), 70);
}

TEST_F(ElectricCarTest, TestOfNegateiveAccelerateException) {
    EXPECT_THROW(electricCarTest.accelerate(-700), InvalidSpeed);
}

TEST_F(ElectricCarTest, TestOfChangeEngineWhenCarIsDrive) {
    electricCarTest.accelerate(120);
    EXPECT_THROW(electricCarTest.changeEngine(std::make_unique<ElectricEngine>(120, 110)), InvalidEngine);
}

TEST_F(ElectricCarTest, TestOfChangeEngineWhenCarIsStopped) {
    electricCarTest.brake();
    EXPECT_NO_THROW(electricCarTest.changeEngine(std::make_unique<ElectricEngine>(120, 110)));
}
