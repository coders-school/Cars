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
  PetrolCar car{std::make_unique<PetrolEngine>(PetrolEngine(120, 1800, 6))};
};

class CarTest : public testing::Test {
protected:
  PetrolCar carPetrol{std::make_unique<PetrolEngine>(PetrolEngine(120, 1800, 6))};
  ElectricCar carElectric{std::make_unique<ElectricEngine>(ElectricEngine(130, 650))};
  HybridCar carHybrid{std::make_unique<PetrolEngine>(PetrolEngine(80, 1400, 5)), std::make_unique<ElectricEngine>(ElectricEngine(100, 540))};
};

// Gearbox tests
TEST_F(GearboxTest, ShouldAllowNormalChange) {
  EXPECT_NO_THROW(car.changeGear(1));
  EXPECT_NO_THROW(car.changeGear(2));
  EXPECT_NO_THROW(car.changeGear(4));
  EXPECT_NO_THROW(car.changeGear(0));
  EXPECT_NO_THROW(car.changeGear(-1));
  EXPECT_NO_THROW(car.changeGear(3));
  EXPECT_NO_THROW(car.changeGear(5));
}
TEST_F(GearboxTest, ShouldThrowIfBadGear) {
  EXPECT_THROW(car.changeGear(8), InvalidGear);
}
TEST_F(GearboxTest, ShouldThrowIfReverseFromHighGear) {
  EXPECT_NO_THROW(car.changeGear(1));
  EXPECT_THROW(car.changeGear(-1), InvalidGear);
}

// Car tests
TEST_F(CarTest, ShouldAllowNormalAcceleration) {
  EXPECT_NO_THROW(carPetrol.accelerate(11));
  EXPECT_NO_THROW(carElectric.accelerate(17)); 
  EXPECT_NO_THROW(carHybrid.accelerate(20));
}

TEST_F(CarTest, ShouldThrowWhenNegativeAcceleration) {
  EXPECT_THROW(carPetrol.accelerate(-50), CarLogicError);
  EXPECT_THROW(carElectric.accelerate(-50), CarLogicError); 
  EXPECT_THROW(carHybrid.accelerate(-50), CarLogicError);
}
