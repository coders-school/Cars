#include "ElectricEngine.hpp"
#include "Exceptions.hpp"
#include "gtest/gtest.h"
#include "HybridCar.hpp"
#include "PetrolEngine.hpp"

constexpr int enginePPower = 186;
constexpr int engineCapacity = 1998.9;
constexpr int gears = 5;
constexpr int maxFuelTank = 180;

constexpr int engineEPower = 200;
constexpr int maxBatteryCapacity = 3000;
constexpr int currentBatteryCapacity = 2000;

constexpr int newEnginePPower = 320;
constexpr int newEngineCapacity = 2499.5;
constexpr int newGears = 6;

constexpr int newEngineEPower = 400;
constexpr int newMaxBatteryCapacity = 6000;
constexpr int newCurrentBatteryCapacity = 3000;

class HybridTestCar : public ::testing::Test {
protected:
    HybridTestCar()
        : hybridCar(std::make_unique<PetrolEngine>(enginePPower, engineCapacity, gears, maxFuelTank),
                    std::make_unique<ElectricEngine>(engineEPower, maxBatteryCapacity, currentBatteryCapacity)){};
    HybridCar hybridCar;
};

TEST_F(HybridTestCar, HybridCarCanAccelerateBy30) {
    EXPECT_NO_THROW(hybridCar.accelerate(30));
}

TEST_F(HybridTestCar, HybridCarCANTAccelerateBy30Below0) {
    EXPECT_THROW(hybridCar.accelerate(-30), InvalidSpeed);
}

TEST_F(HybridTestCar, HybridCarCanDecelerateBy30AfterAccelerateBy50) {
    hybridCar.accelerate(50);
    EXPECT_NO_THROW(hybridCar.decelerate(30));
}

TEST_F(HybridTestCar, HybridCarCANTDecelerateBy30AfterAccelerateBy20) {
    hybridCar.accelerate(20);
    EXPECT_THROW(hybridCar.decelerate(30), InvalidSpeed);
}

TEST_F(HybridTestCar, HybridCarCANTDecelerateBy30Below0AfterAccelerateBy20) {
    hybridCar.accelerate(20);
    EXPECT_THROW(hybridCar.decelerate(-30), InvalidSpeed);
}

TEST_F(HybridTestCar, HybridCarCanChangePetrolEngineAfterStop) {
    hybridCar.brake();
    EXPECT_NO_THROW(hybridCar.changePetrolEngine(std::make_unique<PetrolEngine>(newEnginePPower,
                                                                                newEngineCapacity,
                                                                                newGears,
                                                                                maxFuelTank)));
}

TEST_F(HybridTestCar, HybridCarCANTChangePetrolEngineWhileItIstMoving) {
    hybridCar.accelerate(100);
    EXPECT_THROW(hybridCar.changePetrolEngine(std::make_unique<PetrolEngine>(newEnginePPower,
                                                                             newEngineCapacity, 
                                                                             newGears,
                                                                             maxFuelTank)), 
                                                                             InvalidSpeed);
}

TEST_F(HybridTestCar, HybridCarCanChangeElectricEngineAfterStop) {
    hybridCar.brake();
    EXPECT_NO_THROW(hybridCar.changeElectricEngine(std::make_unique<ElectricEngine>(newEngineEPower,
                                                                                  newMaxBatteryCapacity,
                                                                                  newCurrentBatteryCapacity)));
}

TEST_F(HybridTestCar, HybridCarCANTChangElectricEngineWhileItIstMoving) {
    hybridCar.accelerate(100);
    EXPECT_THROW(hybridCar.changeElectricEngine(std::make_unique<ElectricEngine>(newEnginePPower,
                                                                                 newMaxBatteryCapacity,
                                                                                 newCurrentBatteryCapacity)),
                                                                                 InvalidSpeed);
}

TEST_F(HybridTestCar, HybridCarCanChargeWhenHasLowerBatteryCapacityThanengineCapacity) {
    EXPECT_NO_THROW(hybridCar.ElectricCar::restore());
}

TEST_F(HybridTestCar, HybridCarCANTChargeWhenItsFull) {
    hybridCar.ElectricCar::restore();
    EXPECT_THROW(hybridCar.ElectricCar::restore(), InvalidRestore);
}

TEST_F(HybridTestCar, HybridCarCanRefuelWhenHasLowerTankLevelThanMax) {
    EXPECT_NO_THROW(hybridCar.PetrolCar::restore());
}

TEST_F(HybridTestCar, HybridCarCANTRefuelWhenTankIsFull) {
    hybridCar.PetrolCar::restore();
    EXPECT_THROW(hybridCar.PetrolCar::restore(), InvalidRestore);
}

TEST_F(HybridTestCar, HybridCarCanChangeTheDriveMode) {
    EXPECT_NO_THROW(hybridCar.changeDriveMode(-1));
    EXPECT_NO_THROW(hybridCar.changeDriveMode(0));
    EXPECT_NO_THROW(hybridCar.changeDriveMode(1));
}

TEST_F(HybridTestCar, HybridCarCANTHasTheseDrivingModes) {
    EXPECT_THROW(hybridCar.changeDriveMode(-2), InvalidDriveMode);
    EXPECT_THROW(hybridCar.changeDriveMode(7), InvalidDriveMode);
}
