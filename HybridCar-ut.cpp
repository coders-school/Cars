#include <gtest/gtest.h>

#include "Car.hpp"
#include "ElectricEngine.hpp"
#include "HybridCar.hpp"
#include "InvalidEngine.hpp"
#include "InvalidGear.hpp"
#include "InvalidSpeed.hpp"
#include "PetrolEngine.hpp"

constexpr int power = 120;
constexpr float capacity = 3.0;
constexpr int speed = 120;
constexpr int gears = 5;
constexpr int batteryCapacity = 700;

class HybridCarTest : public ::testing::Test {
protected:
    HybridCar hybridCarTest;
    HybridCarTest()
        : hybridCarTest(std::make_shared<PetrolEngine>(power, capacity, gears), std::make_shared<ElectricEngine>(power, batteryCapacity)){};
};

TEST_F(HybridCarTest, ShouldReturnSumOfPetrolCarEnginePowerAndElectricCarEnginePower) {
    EXPECT_EQ(power + power, hybridCarTest.getPower());
}

TEST_F(HybridCarTest, ShouldChangeEngineForElectricCar) {
    constexpr int newPower = 500;
    constexpr float newCapacity = 5.0;
    constexpr int newBatteryCapacity = 1000;
    ASSERT_EQ(hybridCarTest.getPower(), power + power);
    hybridCarTest.changeEngine(std::make_shared<ElectricEngine>(newPower, newBatteryCapacity), std::make_shared<PetrolEngine>(newPower, newCapacity, gears));
    ASSERT_EQ(hybridCarTest.getBatteryCapacity(), newBatteryCapacity);
    ASSERT_EQ(hybridCarTest.getCapacity(), newCapacity);
}

TEST_F(HybridCarTest, ShouldNotChangeVelocityOfHybridCarWhenInputVelocityIsNegativeValue) {
    constexpr int negativeSpeed = -120;
    EXPECT_THROW(hybridCarTest.accelerate(negativeSpeed), InvalidSpeed);
}

TEST_F(HybridCarTest, ShouldNotChangeEngineForHybridCar) {
    constexpr int newPower = 500;
    constexpr float newCapacity = 5.0;
    constexpr int newBatteryCapacity = 1000;
    hybridCarTest.accelerate(speed);
    EXPECT_THROW(hybridCarTest.changeEngine(std::make_shared<ElectricEngine>(newPower, newBatteryCapacity), std::make_shared<PetrolEngine>(newPower, newCapacity, gears)), InvalidEngine);
}

TEST_F(HybridCarTest, ShouldChangeGearInHybridCar) {
    hybridCarTest.changeGear(1);
    ASSERT_EQ(hybridCarTest.getCurrentGear(), 1);
}

TEST_F(HybridCarTest, ShouldNotChangeGearInHybridCarIfThatGearNotExist) {
    EXPECT_THROW(hybridCarTest.changeGear(-2), InvalidGear);
    EXPECT_THROW(hybridCarTest.changeGear(gears+1), InvalidGear);
}

TEST_F(HybridCarTest, ShouldNotChangeGearToReverseFrom3){
    hybridCarTest.changeGear(3);
    EXPECT_THROW(hybridCarTest.changeGear(-1), InvalidGear);
}
