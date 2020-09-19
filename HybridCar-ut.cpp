#include <memory>

#include "Car.hpp"
#include "ElectricEngine.hpp"
#include "Exceptions.hpp"
#include "HybridCar.hpp"
#include "PetrolEngine.hpp"
#include "gtest/gtest.h"

constexpr int power = 120;
constexpr float capacity = 46.5;
constexpr int gears = 5;
constexpr int batteryCapacity = 100;

class HybridCarTest : public ::testing::Test {
protected:
    HybridCarTest()
        : hybridCar(std::make_unique<PetrolEngine>(power, capacity, gears),
                    std::make_unique<ElectricEngine>(power, batteryCapacity)){};
    HybridCar hybridCar;
};

TEST_F(HybridCarTest, HybridCarCanAccelerate) {
    hybridCar.accelerate(50);
    ASSERT_EQ(hybridCar.getSpeed(), 50);
}

TEST_F(HybridCarTest, HybridCarCannotReachNegativeSpeed) {
    EXPECT_THROW(hybridCar.accelerate(-2), InvalidAcceleration);
}

TEST_F(HybridCarTest, HybridCannotChangeEngineDuringRide) {
    int newPower = 150;
    float newCapacity = 50.5;
    hybridCar.accelerate(50);
    EXPECT_THROW(hybridCar.changeEngine(std::make_unique<ElectricEngine>(power, batteryCapacity),
                                        std::make_unique<PetrolEngine>(newPower, newCapacity, gears)),
                 InvalidEngineChange);
}

TEST_F(HybridCarTest, HybridCanChangeGear) {
    hybridCar.setGear(1);
    ASSERT_EQ(hybridCar.getCurrentGear(), 1);
}

TEST_F(HybridCarTest, HybridCannotChangeGearToReverseFrom2) {
    hybridCar.setGear(2);
    EXPECT_THROW(hybridCar.setGear(-1), InvalidGear);
}

TEST_F(HybridCarTest, HybridCannotChangeTooManyGearsAtOnce) {
    EXPECT_THROW(hybridCar.setGear(5), InvalidGear);
}

TEST_F(HybridCarTest, HybridCannotBeInitializedWithNegativeCapacity) {
    int newCapacity = -750;
    EXPECT_THROW(hybridCar.changeEngine(std::make_unique<ElectricEngine>(power, batteryCapacity),
                                        std::make_unique<PetrolEngine>(power, newCapacity, gears)),
                 InvalidParameter);
}

TEST_F(HybridCarTest, HybridCannotBeInitializedWithNegativeGearsNumber) {
    int newGears = -4;
    EXPECT_THROW(hybridCar.changeEngine(std::make_unique<ElectricEngine>(power, batteryCapacity),
                                        std::make_unique<PetrolEngine>(power, capacity, newGears)),
                 InvalidParameter);
}

TEST_F(HybridCarTest, HybridCannotBeInitializedWithNegativePetrolPower) {
    int newPower = -50;
    EXPECT_THROW(hybridCar.changeEngine(std::make_unique<ElectricEngine>(power, batteryCapacity),
                                        std::make_unique<PetrolEngine>(newPower, capacity, gears)),
                 InvalidParameter);
}

TEST_F(HybridCarTest, HybridCannotBeInitializedWithNegativeBatteryCapacity) {
    int newBatteryCapacity = -750;
    EXPECT_THROW(hybridCar.changeEngine(std::make_unique<ElectricEngine>(power, newBatteryCapacity),
                                        std::make_unique<PetrolEngine>(power, capacity, gears)),
                 InvalidParameter);
}

TEST_F(HybridCarTest, HybridCannotBeInitializedWithNegativeElectricPower) {
    int newPower = -150;
    EXPECT_THROW(hybridCar.changeEngine(std::make_unique<ElectricEngine>(newPower, batteryCapacity),
                                        std::make_unique<PetrolEngine>(power, capacity, gears)),
                 InvalidParameter);
}
