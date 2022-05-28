#include <gtest/gtest.h>
#include <memory>
#include "Car.hpp"
#include "ElectricCar.hpp"
#include "ElectricEngine.hpp"
#include "HybridCar.hpp"
#include "carExceptions.hpp"
#include "PetrolCar.hpp"
#include "PetrolEngine.hpp"

class GearboxTest : public testing::Test {
protected:
// petrol engine
};

class CarTest : public testing::Test {
protected:
// petrol car
// electric car
// hybrid car
};

// Gearbox tests
TEST_F(GearboxTest, ShouldAllowNormalChange) {
  EXPECT_EQ(1, 2);
}
TEST_F(GearboxTest, ShouldThrowIfBadGear) {
  EXPECT_EQ(1, 2);
}
TEST_F(GearboxTest, ShouldThrowIfReverseFromHighGear) {
  EXPECT_EQ(1, 2);
}

// Car tests
TEST_F(CarTest, ShouldAllowEngineChangeToSameType) {
  EXPECT_EQ(1, 2);
}
TEST_F(CarTest, ShouldThrowWhenEngineChangeToWrongType) {
  EXPECT_EQ(1, 2);
}
TEST_F(CarTest, ShouldThrowWhenEmptyEngineChange) {
  EXPECT_EQ(1, 2);
}
