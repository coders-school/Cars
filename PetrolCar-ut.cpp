#include <gtest/gtest.h>
#include <memory>
#include <stdexcept>

#include "car/PetrolCar.hpp"
#include "engine/PetrolEngine.hpp"
#include "exception/InvalidEngineChange.hpp"
#include "exception/InvalidGear.hpp"
#include "exception/InvalidSpeed.hpp"
#include "exception/InvalidParameter.hpp"

struct PetrolCarTest : ::testing::Test {
    int power{ 110 };
    float capacity{ 1.8 };
    int gears{ 5 };
    PetrolCar petrolCar{ std::make_unique<PetrolEngine>(power, capacity, gears) };
};

TEST_F(PetrolCarTest, ShouldChangeGearProperly) {
    petrolCar.changeGear(1);
    EXPECT_EQ(petrolCar.getCurrentGear(), 1);    
}

TEST_F(PetrolCarTest, ShouldChangeRevereseGearProperlyWhenStopped) {
    petrolCar.changeGear(-1);
    EXPECT_EQ(petrolCar.getCurrentGear(), -1);    
}

TEST_F(PetrolCarTest, ShouldNotChangeGearButThrowException) {
    EXPECT_THROW(petrolCar.changeGear(42), InvalidGear);    
}

TEST_F(PetrolCarTest, ShouldNotChangeGearWhileDrivigToReverse) {
    petrolCar.changeGear(2);
    petrolCar.accelerate(42);
    EXPECT_THROW(petrolCar.changeGear(-1), InvalidGear);    
}

TEST_F(PetrolCarTest, ShouldAccelerateProperly) {
    petrolCar.accelerate(42);
    EXPECT_EQ(petrolCar.getSpeed(), 42);    
}

TEST_F(PetrolCarTest, ShoulNotAccelerateButThrowException) {
    EXPECT_THROW(petrolCar.accelerate(-42), InvalidSpeed);    
}

TEST_F(PetrolCarTest, ShouldBrake) {
    petrolCar.brake();
    EXPECT_EQ(petrolCar.getSpeed(), 0);
}

TEST_F(PetrolCarTest, EngineShouldBeChangedWhenStopped) {
    EXPECT_NO_THROW(petrolCar.changeEngine(std::make_unique<PetrolEngine>(power, capacity, gears)));
}

TEST_F(PetrolCarTest, EngineNotShouldBeChangedWhileDriving) {
    petrolCar.accelerate(42);
    EXPECT_THROW(petrolCar.changeEngine(std::make_unique<PetrolEngine>(power, capacity, gears)),
                 InvalidEngineChange);
}

TEST_F(PetrolCarTest, EngingeCannotBeInitializedWithNegativeCapacity) {
    capacity = -1.8;
    EXPECT_THROW(petrolCar.changeEngine(std::make_unique<PetrolEngine>(power, capacity, gears)),
                 InvalidParameter);
}

TEST_F(PetrolCarTest, EngingeCannotBeInitializedWithNegativeGear) {
    gears = -5;
    EXPECT_THROW(petrolCar.changeEngine(std::make_unique<PetrolEngine>(power, capacity, gears)),
                 InvalidParameter);
}

TEST_F(PetrolCarTest, EngingeCannotBeInitializedWithNegativePower) {
    power = -110;
    EXPECT_THROW(petrolCar.changeEngine(std::make_unique<PetrolEngine>(power, capacity, gears)),
                 InvalidParameter);
}
