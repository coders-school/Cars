#include <gtest/gtest.h>

#include "HybridCar.hpp"
#include "InvalidGear.hpp"

struct HybridCarTest : ::testing::Test {
    HybridCarTest()
        : car(new PetrolEngine(petrolPower, 2.0, maxGear), new ElectricEngine(electricPower, 400)) {}

    const int petrolPower = 200;
    const int maxGear = 5;
    const int electricPower = 300;
    HybridCar car;
};

TEST_F(HybridCarTest, shouldChangeGear) {
    ASSERT_NO_THROW(car.changeGear(4));
    ASSERT_EQ(car.getCurrentGear(), 4);
}

TEST_F(HybridCarTest, shouldThrowExceptionWhenGearOutOfRange) {
    ASSERT_THROW(car.changeGear(-2), InvalidGear);
    ASSERT_THROW(car.changeGear(maxGear + 1), InvalidGear);
}

TEST_F(HybridCarTest, shouldThrowExceptionWhenGearChangedToRFromHighGear) {
    car.changeGear(2);
    ASSERT_THROW(car.changeGear(-1), InvalidGear);
}

TEST_F(HybridCarTest, shouldChangePetrolEngine) {
    constexpr int newPower = 300;
    car.changeEngine(new PetrolEngine(newPower, 5.0, maxGear));
    ASSERT_EQ(car.getPetrolPower(), newPower);
}

TEST_F(HybridCarTest, shouldNotChangePetrolEngineDuringDriving) {
    car.accelerate(100);
    car.changeEngine(new PetrolEngine(petrolPower + 100, 5.0, maxGear));
    ASSERT_EQ(car.getPetrolPower(), petrolPower);
}

TEST_F(HybridCarTest, shouldChangeElectricEngine) {
    constexpr int newPower = 300;
    car.changeEngine(new ElectricEngine(newPower, 650));
    ASSERT_EQ(car.getElectricPower(), newPower);
}

TEST_F(HybridCarTest, shouldNotChangeElectricEngineDuringDriving) {
    car.accelerate(100);
    car.changeEngine(new ElectricEngine(electricPower + 100, 400));
    ASSERT_EQ(car.getElectricPower(), electricPower);
}

TEST_F(HybridCarTest, shouldChangeSpeed) {
    constexpr int newSpeed = 100;
    ASSERT_EQ(car.getSpeed(), 0);
    car.accelerate(newSpeed);
    ASSERT_EQ(car.getSpeed(), newSpeed);
}

TEST_F(HybridCarTest, shouldNotChangeSpeedToInvalidValue) {
    ASSERT_EQ(car.getSpeed(), 0);
    car.accelerate(-100);
    ASSERT_EQ(car.getSpeed(), 0);
}
