#include <gtest/gtest.h>
#include "ElectricEngine.hpp"
#include "Errors.hpp"
#include "PetrolCar.hpp"

struct PetrolCarTest : public ::testing::Test {
    PetrolCarTest()
        : testPetrolCar(new PetrolEngine(power, capacity, gears)) {}

    const int power = 120;
    const float capacity = 1800;
    const int gears = 6;
    PetrolCar testPetrolCar;

    const int newPower = 100;
    const int newCapacity = 600;
    const int newGear = 4;
    const int rearGear = -1;
};

TEST_F(PetrolCarTest, ShouldSetSpeed100) {
    constexpr int testSpeed = 100;
    testPetrolCar.setSpeed(testSpeed);
    ASSERT_EQ(testPetrolCar.getSpeed(), testSpeed);
}

TEST_F(PetrolCarTest, ShouldNotSetSpeedAbove200) {
    constexpr int initialSpeed = 0;
    constexpr int testSpeed = 250;
    testPetrolCar.setSpeed(testSpeed);
    ASSERT_EQ(testPetrolCar.getSpeed(), initialSpeed);
}

TEST_F(PetrolCarTest, ShouldNotSetSpeedUnderMinus20) {
    constexpr int initialSpeed = 0;
    constexpr int testSpeed = -100;
    testPetrolCar.setSpeed(testSpeed);
    ASSERT_EQ(testPetrolCar.getSpeed(), initialSpeed);
}

TEST_F(PetrolCarTest, ShouldNotAccelerateToLowerSpeed) {
    constexpr int initialSpeed = 100;
    testPetrolCar.setSpeed(initialSpeed);
    constexpr int testSpeed = 50;
    testPetrolCar.accelerate(testSpeed);
    ASSERT_EQ(testPetrolCar.getSpeed(), initialSpeed);
}

TEST_F(PetrolCarTest, ShouldAccelerateFrom50To100) {
    constexpr int initialSpeed = 50;
    testPetrolCar.setSpeed(initialSpeed);
    constexpr int testSpeed = 100;
    testPetrolCar.accelerate(testSpeed);
    ASSERT_EQ(testPetrolCar.getSpeed(), testSpeed);
}

TEST_F(PetrolCarTest, ShouldNotBrakeToHigherSpeed) {
    constexpr int initialSpeed = 100;
    testPetrolCar.setSpeed(initialSpeed);
    constexpr int testSpeed = 150;
    testPetrolCar.brake(testSpeed);
    ASSERT_EQ(testPetrolCar.getSpeed(), initialSpeed);
}

TEST_F(PetrolCarTest, ShouldBrakeFrom100to50) {
    constexpr int initialSpeed = 100;
    testPetrolCar.setSpeed(initialSpeed);
    constexpr int testSpeed = 50;
    testPetrolCar.brake(testSpeed);
    ASSERT_EQ(testPetrolCar.getSpeed(), testSpeed);
}

TEST_F(PetrolCarTest, ShouldChangeEngine) {
    testPetrolCar.changeEngine(new PetrolEngine(newPower, newCapacity, newGear));
    ASSERT_EQ(testPetrolCar.getPetrolEnginePower(), newPower);
    ASSERT_EQ(testPetrolCar.getPetrolEngineCapacity(), newCapacity);
}

TEST_F(PetrolCarTest, ShouldNotChangeEngineDuringDrive) {
    testPetrolCar.setSpeed(100);
    testPetrolCar.changeEngine(new PetrolEngine(newPower, newCapacity, newGear));
    ASSERT_EQ(testPetrolCar.getPetrolEnginePower(), power);
    ASSERT_EQ(testPetrolCar.getPetrolEngineCapacity(), capacity);
}

TEST_F(PetrolCarTest, ShouldNotChangeEngineForPetrolEngine) {
    testPetrolCar.setSpeed(100);
    testPetrolCar.changeEngine(new PetrolEngine(newPower, newCapacity, 5));
    ASSERT_EQ(testPetrolCar.getPetrolEnginePower(), power);
    ASSERT_EQ(testPetrolCar.getPetrolEngineCapacity(), capacity);
}

TEST_F(PetrolCarTest, ShouldChangeGeartoMinus1) {
    testPetrolCar.setGear(rearGear);
    ASSERT_EQ(testPetrolCar.getGear(), rearGear);
}

TEST_F(PetrolCarTest, ShouldChangeGearTo4) {
    testPetrolCar.setGear(newGear);
    ASSERT_EQ(testPetrolCar.getGear(), newGear);
}

TEST_F(PetrolCarTest, ShouldNotChangeGearToMinus1From4) {
    testPetrolCar.setGear(newGear);
    testPetrolCar.setGear(rearGear);
    ASSERT_EQ(testPetrolCar.getGear(), newGear);
}
