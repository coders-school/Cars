#include "gtest/gtest.h"

#include "CarInMovementExcept.hpp"
#include "HybridCar.hpp"
#include "InvalidGear.hpp"

struct HybridTest : public ::testing::Test {
    const int petrolEnginePower = 100;
    const int electricEnginePower = 120;
    const int gearAmount = 6;
    const int petrolCapacity = 3;
    const int batteryCapacity = 200;

    HybridCar testCar;

    HybridTest()
        : testCar(new PetrolEngine(petrolEnginePower, petrolCapacity, gearAmount), new ElectricEngine(electricEnginePower, batteryCapacity)) {}
};

TEST_F(HybridTest, ShouldReturnValidPower) {
    const int validPower = petrolEnginePower + electricEnginePower;

    ASSERT_EQ(validPower, testCar.getEnginePower());
}

TEST_F(HybridTest, shouldThrowErrorWhenChangingEngineInTransit) {
    testCar.accelerate(10);
    EXPECT_THROW(testCar.changeEngine(new ElectricEngine(100, 2)), CarInMovementExcept);
}

TEST_F(HybridTest, ShouldAcceleratePositiveValues) {
    const int finalSpeed = 20;
    testCar.accelerate(finalSpeed);

    ASSERT_EQ(finalSpeed, testCar.checkSpeed());
}

TEST_F(HybridTest, ShouldNotAccelerateWrongVaue) {
    const int finalSpeed = 10;
    testCar.accelerate(finalSpeed);
    testCar.accelerate(-10);

    ASSERT_EQ(finalSpeed, testCar.checkSpeed());
}

TEST_F(HybridTest, shouldChangeEngine) {
    const int pEnginePower = 200;
    const int eEnginePower = 320;
    const int validPower = eEnginePower + pEnginePower;

    testCar.changeEngine(new ElectricEngine(eEnginePower, batteryCapacity));
    testCar.changeEngine(new PetrolEngine(pEnginePower, petrolCapacity, gearAmount));

    ASSERT_EQ(validPower, testCar.getEnginePower());
}

TEST_F(HybridTest, ShouldBreak) {
    const int parkedSpeed = 0;

    testCar.brake();

    ASSERT_EQ(parkedSpeed, testCar.checkSpeed());
}

TEST_F(HybridTest, ShouldChangeGear) {
    const int finalGear = 3;

    testCar.changeGear(finalGear);

    ASSERT_EQ(finalGear, testCar.getCurrentGear());
}

TEST_F(HybridTest, ShouldNotChangeGearOutsideOfNegativeRange) {
    const int finalGear = -3;

    EXPECT_THROW(testCar.changeGear(finalGear), InvalidGear);
}

TEST_F(HybridTest, ShouldNotChangeGearOutsideOfPositiveRange) {
    const int finalGear = 10;

    EXPECT_THROW(testCar.changeGear(finalGear), InvalidGear);
}