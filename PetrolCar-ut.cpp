#include "Exceptions.hpp"
#include "PetrolCar.hpp"
#include "PetrolEngine.hpp"
#include "gtest/gtest.h"

constexpr int enginePower = 186;
constexpr int engineCapacity = 1998.9;
constexpr int gears = 5;
constexpr int maxFuelTank = 180;

constexpr int newEnginePower = 320;
constexpr int newEngineCapacity = 2499.5;
constexpr int newGears = 6;

class PetrolTestCar : public ::testing::Test {
protected:
    PetrolTestCar()
        : petrolCar(std::make_unique<PetrolEngine>(enginePower, engineCapacity, gears, maxFuelTank)){};
    PetrolCar petrolCar;
};

TEST_F(PetrolTestCar, PetrolCarCanAccelerateBy30) {
    EXPECT_NO_THROW(petrolCar.accelerate(30));
}

TEST_F(PetrolTestCar, PetrolCarCANTAccelerateBy30Below0) {
    EXPECT_THROW(petrolCar.accelerate(-30), InvalidSpeed);
}

TEST_F(PetrolTestCar, PetrolCarCanDecelerateBy30AfterAccelerateBy50) {
    petrolCar.accelerate(50);
    EXPECT_NO_THROW(petrolCar.decelerate(30));
}

TEST_F(PetrolTestCar, PetrolCarCANTDecelerateBy30AfterAccelerateBy20) {
    petrolCar.accelerate(20);
    EXPECT_THROW(petrolCar.decelerate(30), InvalidSpeed);
}

TEST_F(PetrolTestCar, PetrolCarCANTDecelerateBy30Below0AfterAccelerateBy20) {
    petrolCar.accelerate(20);
    EXPECT_THROW(petrolCar.decelerate(-30), InvalidSpeed);
}

TEST_F(PetrolTestCar, PetrolCarCanChangeEngineAfterStop) {
    petrolCar.brake();
    EXPECT_NO_THROW(petrolCar.changePetrolEngine(std::make_unique<PetrolEngine>(newEnginePower,
                                                                                newEngineCapacity,
                                                                                newGears,
                                                                                maxFuelTank)));
}

TEST_F(PetrolTestCar, PetrolCarCANTChangeEngineWhileItIstMoving) {
    petrolCar.accelerate(100);
    EXPECT_THROW(petrolCar.changePetrolEngine(std::make_unique<PetrolEngine>(newEnginePower,
                                                                             newEngineCapacity,
                                                                             newGears,
                                                                             maxFuelTank)),
                 InvalidSpeed);
}

TEST_F(PetrolTestCar, PetrolCarCanChargeWhenHasLowerBatteryCapacityThanengineCapacity) {
    EXPECT_NO_THROW(petrolCar.restore());
}

TEST_F(PetrolTestCar, PetrolCarCANTChargeWhenItsFull) {
    petrolCar.restore();
    EXPECT_THROW(petrolCar.restore(), InvalidRestore);
}

TEST_F(PetrolTestCar, PetrolCarCanChangeTheGear) {
    EXPECT_NO_THROW(petrolCar.changeGear(-1));
    EXPECT_NO_THROW(petrolCar.changeGear(0));
    EXPECT_NO_THROW(petrolCar.changeGear(6));
}

TEST_F(PetrolTestCar, PetrolCarCANTChargeTheWrongGear) {
    EXPECT_THROW(petrolCar.changeGear(-2), InvalidGear);
    EXPECT_THROW(petrolCar.changeGear(7), InvalidGear);
}
