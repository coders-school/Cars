#include "gtest/gtest.h"
#include "Car.hpp"
#include "PetrolCar.hpp"
#include "ElectricCar.hpp"
#include "HybridCar.hpp"
#include "InvalidGear.hpp""


// Tests throwing std::range_error when accelerate to speed = -999 or speed > maxSpeed is invoked
TEST(PetrolCarClassTest, ShouldThrowRangeError) {
    PetrolCar opel(std::make_unique<PetrolEngine>(120, 1800, 6));
    EXPECT_THROW(opel.accelerate(-999), std::range_error);
    EXPECT_THROW(opel.accelerate(350), std::range_error);

}
// Tests throwing InvalidGear when wrong gear is set
TEST(PetrolCarChangeGearTest, ShouldThrowIvalidGear) {
    PetrolCar opel(std::make_unique<PetrolEngine>(120, 1800, 6));
    EXPECT_THROW(opel.changeGear(-2), InvalidGear);
    EXPECT_THROW(opel.changeGear(7), InvalidGear);
    EXPECT_THROW(opel.changeGear(2), InvalidGear);
    opel.changeGear(1);
    EXPECT_THROW(opel.changeGear(5), InvalidGear);
}
// Tests if changeGear doesn't throw an exception
TEST(PetrolCarChangeGearTest, ShouldNotThrowException) {
    PetrolCar opel(std::make_unique<PetrolEngine>(120, 1800, 6));
    EXPECT_NO_THROW(opel.changeGear(1));
    EXPECT_NO_THROW(opel.changeGear(2));
    EXPECT_NO_THROW(opel.changeGear(3));    
    EXPECT_NO_THROW(opel.changeGear(2));
    EXPECT_NO_THROW(opel.changeGear(1));
    EXPECT_NO_THROW(opel.changeGear(0));
    EXPECT_NO_THROW(opel.changeGear(-1));
}
// Tests throwing std::range_error when accelerate to speed = -999 or speed > maxSpeed is invoked
TEST(ElectricCarClassTest, ShouldThrowRangeError) {
    ElectricCar nissan(std::make_unique<ElectricEngine>(130, 650));
    EXPECT_THROW(nissan.accelerate(-999), std::range_error);
    EXPECT_THROW(nissan.accelerate(350), std::range_error);
}
// Tests throwing std::invalid_argument when changing engine for the wrong one
TEST(CarClassPointerTest, ShouldThrowInvalidArgument) {
    ElectricCar nissan(std::make_unique<ElectricEngine>(130, 650));
    Car * car = &nissan;
    // Electric car can't have petrol engine
    EXPECT_THROW(car->changeEngine(std::make_unique<PetrolEngine>(150, 700, 7)), std::invalid_argument); 
    PetrolCar opel(std::make_unique<PetrolEngine>(120, 1800, 6));
    car = &opel;
    // Petrol car can't have electric engine
    EXPECT_THROW(car->changeEngine(std::make_unique<ElectricEngine>(130, 650)), std::invalid_argument);
}

