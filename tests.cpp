#include "gtest/gtest.h"
#include "Car.hpp"
#include "ElectricCar.hpp"
#include "Exceptions.hpp"
#include "PetrolCar.hpp"

struct ChangingGearFixture : public ::testing::Test {
  PetrolEngine cut{120, 1800, 6};  
};

TEST_F(ChangingGearFixture, ShouldSetCorrectGear) {
  cut.changeGear(3);
  EXPECT_EQ(cut.getCurrentGear(), 3);
}

TEST_F(ChangingGearFixture, ShouldThrowWhenGearTooHigh) {
  EXPECT_THROW(cut.changeGear(8), InvalidGear);
}

TEST_F(ChangingGearFixture, ShouldThrowWhenGearTooLow) {
  EXPECT_THROW(cut.changeGear(-2), InvalidGear);
}

TEST_F(ChangingGearFixture, ShouldNoThrowWhenNeutral) {
  EXPECT_NO_THROW(cut.changeGear(0));
}

TEST_F(ChangingGearFixture, ShouldNoThrowWhenRear) {
  EXPECT_NO_THROW(cut.changeGear(-1));
}

struct AccelerateTestFixture : public ::testing::Test {
  ElectricCar cut{new ElectricEngine(130, 650)};
};

TEST_F(AccelerateTestFixture, ShouldSetCorrectSpeed) {
  cut.accelerate(50);
  EXPECT_EQ(cut.getSpeed(), 50);
}

TEST_F(AccelerateTestFixture, ShouldThrowInvalidSpeedWhenNegative) {
  EXPECT_THROW(cut.accelerate(-4), InvalidSpeed);
}

TEST_F(AccelerateTestFixture, ShouldThrowInvalidSpeedWhenTooHigh) {
  EXPECT_THROW(cut.accelerate(999), InvalidSpeed);
}
