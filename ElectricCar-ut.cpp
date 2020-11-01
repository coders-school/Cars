#include "ElectricCar.hpp"
#include "ElectricEngine.hpp"
#include "Exceptions.hpp"
#include "gtest/gtest.h"

constexpr int enginePower = 200;
constexpr int maxBatteryCapacity = 3000;
constexpr int currentBatteryCapacity = 2000;

constexpr int newEnginePower = 400;
constexpr int newMaxBatteryCapacity = 6000;
constexpr int newCurrentBatteryCapacity = 3000;

class ElectricTestCar : public ::testing::Test {
protected:
    ElectricTestCar()
        : electricCar(std::make_unique<ElectricEngine>(enginePower, maxBatteryCapacity, currentBatteryCapacity)){};
    ElectricCar electricCar;
};

TEST_F(ElectricTestCar, ElectricCarCanAccelerateBy30) {
    EXPECT_NO_THROW(electricCar.accelerate(30));
}

TEST_F(ElectricTestCar, ElectricCarCANTAccelerateBy30Below0) {
    EXPECT_THROW(electricCar.accelerate(-30), InvalidSpeed);
}

TEST_F(ElectricTestCar, ElectricCarCanDecelerateBy30AfterAccelerateBy50) {
    electricCar.accelerate(50);
    EXPECT_NO_THROW(electricCar.decelerate(30));
}

TEST_F(ElectricTestCar, ElectricCarCANTDecelerateBy30AfterAccelerateBy20) {
    electricCar.accelerate(20);
    EXPECT_THROW(electricCar.decelerate(30), InvalidSpeed);
}

TEST_F(ElectricTestCar, ElectricCarCANTDecelerateBy30Below0AfterAccelerateBy20) {
    electricCar.accelerate(20);
    EXPECT_THROW(electricCar.decelerate(-30), InvalidSpeed);
}

TEST_F(ElectricTestCar, ElectricCarCanChangeEngineAfterStop) {
    electricCar.brake();
    EXPECT_NO_THROW(electricCar.changeElectricEngine(std::make_unique<ElectricEngine>(newEnginePower,
                                                                                      newMaxBatteryCapacity,
                                                                                      newCurrentBatteryCapacity)));
}

TEST_F(ElectricTestCar, ElectricCarCANTChangeEngineWhileItIstMoving) {
    electricCar.accelerate(100);
    EXPECT_THROW(electricCar.changeElectricEngine(std::make_unique<ElectricEngine>(newEnginePower,
                                                                                   newMaxBatteryCapacity,
                                                                                   newCurrentBatteryCapacity)),
                                                                                   InvalidSpeed);
}

TEST_F(ElectricTestCar, ElectricCarCanChargeWhenHasLowerBatteryCapacityThanMaxBatteryCapacity) {
    EXPECT_NO_THROW(electricCar.restore());
}

TEST_F(ElectricTestCar, ElectricCarCANTChargeWhenItsFull) {
    electricCar.restore();
    EXPECT_THROW(electricCar.restore(), InvalidRestore);
}
