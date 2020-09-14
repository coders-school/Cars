#include <gtest/gtest.h>
#include "ElectricCar.hpp"
#include "PetrolEngine.hpp"

struct ElectricCarTest : public ::testing::Test {
    ElectricCarTest()
        : testElectricCar(new ElectricEngine(power, capacity)) {}

    const int power = 130;
    const int capacity = 650;
    ElectricCar testElectricCar;

    const int newPower = 100;
    const int newCapacity = 600;
};

TEST_F(ElectricCarTest, ShouldSetSpeed100) {
    constexpr int testSpeed = 100;
    testElectricCar.setSpeed(testSpeed);
    ASSERT_EQ(testElectricCar.getSpeed(), testSpeed);
}

TEST_F(ElectricCarTest, ShouldNotSetSpeedAbove200) {
    constexpr int initialSpeed = 0;
    constexpr int testSpeed = 250;
    testElectricCar.setSpeed(testSpeed);
    ASSERT_EQ(testElectricCar.getSpeed(), initialSpeed);
}

TEST_F(ElectricCarTest, ShouldNotSetSpeedUnderMinus20) {
    constexpr int initialSpeed = 0;
    constexpr int testSpeed = -100;
    testElectricCar.setSpeed(testSpeed);
    ASSERT_EQ(testElectricCar.getSpeed(), initialSpeed);
}

TEST_F(ElectricCarTest, ShouldNotAccelerateToLowerSpeed) {
    constexpr int initialSpeed = 100;
    testElectricCar.setSpeed(initialSpeed);
    constexpr int testSpeed = 50;
    testElectricCar.accelerate(testSpeed);
    ASSERT_EQ(testElectricCar.getSpeed(), initialSpeed);
}

TEST_F(ElectricCarTest, ShouldAccelerateFrom50To100) {
    constexpr int initialSpeed = 50;
    testElectricCar.setSpeed(initialSpeed);
    constexpr int testSpeed = 100;
    testElectricCar.accelerate(testSpeed);
    ASSERT_EQ(testElectricCar.getSpeed(), testSpeed);
}

TEST_F(ElectricCarTest, ShouldNotBrakeToHigherSpeed) {
    constexpr int initialSpeed = 100;
    testElectricCar.setSpeed(initialSpeed);
    constexpr int testSpeed = 150;
    testElectricCar.brake(testSpeed);
    ASSERT_EQ(testElectricCar.getSpeed(), initialSpeed);
}

TEST_F(ElectricCarTest, ShouldBrakeFrom100to50) {
    constexpr int initialSpeed = 100;
    testElectricCar.setSpeed(initialSpeed);
    constexpr int testSpeed = 50;
    testElectricCar.brake(testSpeed);
    ASSERT_EQ(testElectricCar.getSpeed(), testSpeed);
}

TEST_F(ElectricCarTest, ShouldChangeEngine) {
    testElectricCar.changeEngine(new ElectricEngine(newPower, newCapacity));
    ASSERT_EQ(testElectricCar.getElectricEnginePower(), newPower);
    ASSERT_EQ(testElectricCar.getElectricEngineBatteryCapacity(), newCapacity);
}

TEST_F(ElectricCarTest, ShouldNotChangeEngineDuringDrive) {
    testElectricCar.setSpeed(100);
    testElectricCar.changeEngine(new ElectricEngine(newPower, newCapacity));
    ASSERT_EQ(testElectricCar.getElectricEnginePower(), power);
    ASSERT_EQ(testElectricCar.getElectricEngineBatteryCapacity(), capacity);
}

TEST_F(ElectricCarTest, ShouldNotChangeEngineForPetrolEngine) {
    testElectricCar.setSpeed(100);
    testElectricCar.changeEngine(new PetrolEngine(newPower, newCapacity, 5));
    ASSERT_EQ(testElectricCar.getElectricEnginePower(), power);
    ASSERT_EQ(testElectricCar.getElectricEngineBatteryCapacity(), capacity);
}