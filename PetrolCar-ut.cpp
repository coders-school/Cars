#include <gtest/gtest.h>
#include <memory>
#include "Car.hpp"
#include "InvalidsError.hpp"
#include "PetrolCar.hpp"
#include "PetrolEngine.hpp"

constexpr int power = 150;
constexpr float capacity = 100;
constexpr int gears = 6;
constexpr int currentGear = 0;

class PetrolCarTest : public ::testing::Test {
protected:
    PetrolCar petrolCarTest{std::make_unique<PetrolEngine>(power, capacity, gears)};
};

TEST_F(PetrolCarTest, TestOfAccelerate) {
    petrolCarTest.accelerate(70);
    ASSERT_EQ(petrolCarTest.getSpeed(), 70);
}

TEST_F(PetrolCarTest, TestOfNegateiveAccelerateException) {
    EXPECT_THROW(petrolCarTest.accelerate(-700), InvalidSpeed);
}

TEST_F(PetrolCarTest, TestOfChangeGear) {
    petrolCarTest.setGear(1);
    ASSERT_EQ(petrolCarTest.getGear(), 1);
}

TEST_F(PetrolCarTest, TestOfChangeTooManyGears) {
    petrolCarTest.setGear(1);
    petrolCarTest.setGear(2);
    petrolCarTest.setGear(3);
    petrolCarTest.setGear(4);
    EXPECT_THROW(petrolCarTest.setGear(-1), InvalidGear);
}

TEST_F(PetrolCarTest, TestOfChangeEngineWhenCarIsDrive) {
    petrolCarTest.accelerate(120);
    EXPECT_THROW(petrolCarTest.changeEngine(std::make_unique<PetrolEngine>(120, 110, 5)), InvalidEngine);
}

TEST_F(PetrolCarTest, TestOfChangeEngineWhenCarIsStopped) {
    petrolCarTest.brake();
    EXPECT_NO_THROW(petrolCarTest.changeEngine(std::make_unique<PetrolEngine>(120, 110, 5)));
}
