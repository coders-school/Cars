#include <gtest/gtest.h>

#include "ElectricEngine.hpp"
#include "InvalidGear.hpp"
#include "PetrolCar.hpp"

struct PetrolCarTest : ::testing::Test {
    PetrolCarTest()
        : opel(new PetrolEngine(power, 5.0, maxGear)) {}

    const int power = 120;
    const int maxGear = 5;
    PetrolCar opel;
};

TEST_F(PetrolCarTest, shouldChangeGear) {
    ASSERT_NO_THROW(opel.changeGear(4));
    ASSERT_EQ(opel.getCurrentGear(), 4);
}

TEST_F(PetrolCarTest, shouldThrowExceptionWhenGearOutOfRange) {
    ASSERT_THROW(opel.changeGear(-2), InvalidGear);
    ASSERT_THROW(opel.changeGear(maxGear + 1), InvalidGear);
}

TEST_F(PetrolCarTest, shouldThrowExceptionWhenGearChangedToRFromHighGear) {
    opel.changeGear(2);
    ASSERT_THROW(opel.changeGear(-1), InvalidGear);
}

TEST_F(PetrolCarTest, shouldChangeEngines) {
    constexpr int newPower = 300;
    opel.changeEngine(new PetrolEngine(newPower, 5.0, maxGear));
    ASSERT_EQ(opel.getPetrolPower(), newPower);
}

TEST_F(PetrolCarTest, shouldNotChangeEngineDuringDriving) {
    opel.accelerate(100);
    opel.changeEngine(new PetrolEngine(power + 100, 5.0, maxGear));
    ASSERT_EQ(opel.getPetrolPower(), power);
}

TEST_F(PetrolCarTest, shouldPreventFromInvalidEngineChange) {
    opel.changeEngine(new ElectricEngine(300, 5));
    ASSERT_EQ(opel.getPetrolPower(), power);
}

TEST_F(PetrolCarTest, shouldChangeSpeed) {
    constexpr int newSpeed = 100;
    ASSERT_EQ(opel.getSpeed(), 0);
    opel.accelerate(newSpeed);
    ASSERT_EQ(opel.getSpeed(), newSpeed);
}

TEST_F(PetrolCarTest, shouldNotChangeSpeedToInvalidValue) {
    ASSERT_EQ(opel.getSpeed(), 0);
    opel.accelerate(-100);
    ASSERT_EQ(opel.getSpeed(), 0);
}
