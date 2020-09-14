#include <gtest/gtest.h>

#include "ElectricEngine.hpp"
#include "HybridCar.hpp"
#include "PetrolEngine.hpp"

struct HybridCarTest : public ::testing::Test {
    HybridCarTest()
        : testHybridCar(new PetrolEngine(petrolEnginePower, petrolEngineCapacity, gears),
                        new ElectricEngine(electricEnginePower, electricEngineCapacity)) {}

    const int petrolEnginePower = 120;
    const float petrolEngineCapacity = 1800;
    const int gears = 6;

    const int newPetrolEnginePower = 100;
    const int newPetrolEngineCapacity = 1500;
    const int newGear = 4;
    const int rearGear = -1;

    const int electricEnginePower = 130;
    const int electricEngineCapacity = 650;

    const int newElectricEnginePower = 100;
    const int newElectricEngineCapacity = 600;

    HybridCar testHybridCar;
};

TEST_F(HybridCarTest, ShouldSetSpeed100) {
    constexpr int testSpeed = 100;
    testHybridCar.setSpeed(testSpeed);
    ASSERT_EQ(testHybridCar.getSpeed(), testSpeed);
}

TEST_F(HybridCarTest, ShouldNotSetSpeedAbove200) {
    constexpr int initialSpeed = 0;
    constexpr int testSpeed = 250;
    testHybridCar.setSpeed(testSpeed);
    ASSERT_EQ(testHybridCar.getSpeed(), initialSpeed);
}

TEST_F(HybridCarTest, ShouldNotSetSpeedUnderMinus20) {
    constexpr int initialSpeed = 0;
    constexpr int testSpeed = -100;
    testHybridCar.setSpeed(testSpeed);
    ASSERT_EQ(testHybridCar.getSpeed(), initialSpeed);
}

TEST_F(HybridCarTest, ShouldNotAccelerateToLowerSpeed) {
    constexpr int initialSpeed = 100;
    testHybridCar.setSpeed(initialSpeed);
    constexpr int testSpeed = 50;
    testHybridCar.accelerate(testSpeed);
    ASSERT_EQ(testHybridCar.getSpeed(), initialSpeed);
}

TEST_F(HybridCarTest, ShouldAccelerateFrom50To100) {
    constexpr int initialSpeed = 50;
    testHybridCar.setSpeed(initialSpeed);
    constexpr int testSpeed = 100;
    testHybridCar.accelerate(testSpeed);
    ASSERT_EQ(testHybridCar.getSpeed(), testSpeed);
}

TEST_F(HybridCarTest, ShouldNotBrakeToHigherSpeed) {
    constexpr int initialSpeed = 100;
    testHybridCar.setSpeed(initialSpeed);
    constexpr int testSpeed = 150;
    testHybridCar.brake(testSpeed);
    ASSERT_EQ(testHybridCar.getSpeed(), initialSpeed);
}

TEST_F(HybridCarTest, ShouldBrakeFrom100to50) {
    constexpr int initialSpeed = 100;
    testHybridCar.setSpeed(initialSpeed);
    constexpr int testSpeed = 50;
    testHybridCar.brake(testSpeed);
    ASSERT_EQ(testHybridCar.getSpeed(), testSpeed);
}

TEST_F(HybridCarTest, ShouldChangePetrolEngine) {
    testHybridCar.changeEngine(new PetrolEngine(newPetrolEnginePower,
                                                newPetrolEngineCapacity,
                                                newGear));
    ASSERT_EQ(testHybridCar.getPetrolEnginePower(), newPetrolEnginePower);
    ASSERT_EQ(testHybridCar.getPetrolEngineCapacity(), newPetrolEngineCapacity);
}

TEST_F(HybridCarTest, ShouldChangeElectricEngine) {
    testHybridCar.changeEngine(new ElectricEngine(newElectricEnginePower,
                                                  newElectricEngineCapacity));
    ASSERT_EQ(testHybridCar.getElectricEnginePower(), newElectricEnginePower);
    ASSERT_EQ(testHybridCar.getElectricEngineBatteryCapacity(), newElectricEngineCapacity);
}

TEST_F(HybridCarTest, ShouldNotChangePetrolEngineDuringDrive) {
    testHybridCar.setSpeed(100);
    testHybridCar.changeEngine(new PetrolEngine(newPetrolEnginePower,
                                                newPetrolEngineCapacity,
                                                newGear));
    ASSERT_EQ(testHybridCar.getPetrolEnginePower(), petrolEnginePower);
    ASSERT_EQ(testHybridCar.getPetrolEngineCapacity(), petrolEngineCapacity);
}

TEST_F(HybridCarTest, ShouldChangeElectricElectricEngine) {
    testHybridCar.setSpeed(100);
    testHybridCar.changeEngine(new ElectricEngine(newElectricEnginePower,
                                                  newElectricEngineCapacity));
    ASSERT_EQ(testHybridCar.getElectricEnginePower(), electricEnginePower);
    ASSERT_EQ(testHybridCar.getElectricEngineBatteryCapacity(), electricEngineCapacity);
}

TEST_F(HybridCarTest, ShouldChangeGeartoMinus1) {
    testHybridCar.setGear(rearGear);
    ASSERT_EQ(testHybridCar.getGear(), rearGear);
}

TEST_F(HybridCarTest, ShouldChangeGearTo4) {
    testHybridCar.setGear(newGear);
    ASSERT_EQ(testHybridCar.getGear(), newGear);
}

TEST_F(HybridCarTest, ShouldNotChangeGearToMinus1From4) {
    testHybridCar.setGear(newGear);
    testHybridCar.setGear(rearGear);
    ASSERT_EQ(testHybridCar.getGear(), newGear);
}
