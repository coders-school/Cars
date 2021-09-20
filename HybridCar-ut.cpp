#include <gtest/gtest.h>
#include <memory>
#include <stdexcept>

#include "car/HybridCar.hpp"
#include "engine/PetrolEngine.hpp"
#include "engine/ElectricEngine.hpp"
#include "exception/InvalidEngineChange.hpp"
#include "exception/InvalidGear.hpp"
#include "exception/InvalidSpeed.hpp"
#include "exception/InvalidParameter.hpp"

struct HybridCarTest : ::testing::Test {
    int power{ 110 };
    float capacity{ 1.8 };
    int gears{ 5 };

    float battery_capacity{ 1.8 };
    HybridCar hybridCar{ std::make_unique<PetrolEngine>(power, capacity, gears),
                         std::make_unique<ElectricEngine>(power, battery_capacity) };
};

TEST_F(HybridCarTest, ShouldChangeGearProperly) {
    hybridCar.changeGear(1);
    EXPECT_EQ(hybridCar.getCurrentGear(), 1);    
}

TEST_F(HybridCarTest, ShouldChangeRevereseGearProperlyWhenStopped) {
    hybridCar.changeGear(-1);
    EXPECT_EQ(hybridCar.getCurrentGear(), -1);    
}

TEST_F(HybridCarTest, ShouldNotChangeGearButThrowException) {
    EXPECT_THROW(hybridCar.changeGear(42), InvalidGear);    
}

TEST_F(HybridCarTest, ShouldNotChangeGearWhileDrivigToReverse) {
    hybridCar.changeGear(2);
    hybridCar.accelerate(42);
    EXPECT_THROW(hybridCar.changeGear(-1), InvalidGear);    
}

TEST_F(HybridCarTest, ShouldAccelerateProperly) {
    hybridCar.accelerate(42);
    EXPECT_EQ(hybridCar.getSpeed(), 42);    
}

TEST_F(HybridCarTest, ShoulNotAccelerateButThrowException) {
    EXPECT_THROW(hybridCar.accelerate(-42), InvalidSpeed);    
}

TEST_F(HybridCarTest, ShouldBrake) {
    hybridCar.brake();
    EXPECT_EQ(hybridCar.getSpeed(), 0);
}

TEST_F(HybridCarTest, EnginesShouldBeChangedWhenStopped) {
    EXPECT_NO_THROW(hybridCar.changePetrolEngine(std::make_unique<PetrolEngine>(power, capacity, gears)));
    EXPECT_NO_THROW(hybridCar.changeElectricEngine(std::make_unique<ElectricEngine>(power, battery_capacity)));
}

TEST_F(HybridCarTest, EnginesNotShouldBeChangedWhileDriving) {
    hybridCar.accelerate(42);
    EXPECT_THROW(hybridCar.changePetrolEngine(std::make_unique<PetrolEngine>(power, capacity, gears)),
                 InvalidEngineChange);
    EXPECT_THROW(hybridCar.changeElectricEngine(std::make_unique<ElectricEngine>(power, battery_capacity)),
                 InvalidEngineChange);
}

TEST_F(HybridCarTest, EngineCannotBeInitializedWithNegativeCapacity) {
    capacity = -1.8;
    EXPECT_THROW(hybridCar.changePetrolEngine(std::make_unique<PetrolEngine>(power, capacity, gears)),
                 InvalidParameter);
}

TEST_F(HybridCarTest, EngineCannotBeInitializedWithNegativeBatteryCapacity) {
    battery_capacity = -700;
    EXPECT_THROW(hybridCar.changeElectricEngine(std::make_unique<ElectricEngine>(power, battery_capacity)),
                 InvalidParameter);
}

TEST_F(HybridCarTest, EngineCannotBeInitializedWithNegativeGear) {
    gears = -5;
    EXPECT_THROW(hybridCar.changePetrolEngine(std::make_unique<PetrolEngine>(power, capacity, gears)),
                 InvalidParameter);
}

TEST_F(HybridCarTest, EnginesCannotBeInitializedWithNegativePower) {
    power = -110;
    EXPECT_THROW(hybridCar.changePetrolEngine(std::make_unique<PetrolEngine>(power, capacity, gears)),
                 InvalidParameter);
    EXPECT_THROW(hybridCar.changeElectricEngine(std::make_unique<ElectricEngine>(power, battery_capacity)),
                 InvalidParameter);
}
