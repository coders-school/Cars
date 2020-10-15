#include <gtest/gtest.h>

#include "Car.hpp"
#include "InvalidEngine.hpp"
#include "InvalidGear.hpp"
#include "InvalidSpeed.hpp"
#include "PetrolCar.hpp"
#include "PetrolEngine.hpp"

constexpr int power = 120;
constexpr float capacity = 3.0;
constexpr int speed = 120;
constexpr int gears = 5;

class PetrolCarTest : public ::testing::Test {
protected:
    PetrolCar petrolCarTest;
    PetrolCarTest()
        : petrolCarTest(std::make_shared<PetrolEngine>(power, capacity, gears)){};
};

TEST_F(PetrolCarTest, ShouldChangePetrolCarVelocity) {
    petrolCarTest.accelerate(speed);
    EXPECT_EQ(speed, petrolCarTest.getSpeed());
}

TEST_F(PetrolCarTest, ShouldReturnPetrolCarEnginePower) {
    EXPECT_EQ(power, petrolCarTest.getPower());
}

TEST_F(PetrolCarTest, ShouldReturnPetrolCarBatteryCapacity) {
    EXPECT_EQ(capacity, petrolCarTest.getCapacity());
}

TEST_F(PetrolCarTest, ShouldNotChangeVelocityOfPetrolCarWhenInputVelocityIsNegativeValue) {
    constexpr int negativeSpeed = -120;
    EXPECT_THROW(petrolCarTest.accelerate(negativeSpeed), InvalidSpeed);
}

TEST_F(PetrolCarTest, ShouldChangeEngineForPetrolCar) {
    constexpr int newPower = 666;
    constexpr float newCapacity = 5.0;
    constexpr int newGears = 3;
    ASSERT_EQ(petrolCarTest.getPower(), power);
    petrolCarTest.changeEngine(std::make_shared<PetrolEngine>(newPower, newCapacity, newGears));
    ASSERT_EQ(petrolCarTest.getCapacity(), newCapacity);
    ASSERT_EQ(petrolCarTest.getGears(), newGears);
}

TEST_F(PetrolCarTest, ShouldNotChangeEngineForPetrolCar) {
    constexpr int newPower = 666;
    constexpr float newCapacity = 5.0;
    constexpr int newGears = 3;
    petrolCarTest.accelerate(speed);
    EXPECT_THROW(petrolCarTest.changeEngine(std::make_shared<PetrolEngine>(newPower, newCapacity, newGears)), InvalidEngine);
}

TEST_F(PetrolCarTest, ShouldChangeGearInPetrolCar) {
    petrolCarTest.changeGear(1);
    ASSERT_EQ(petrolCarTest.getCurrentGear(), 1);
}

TEST_F(PetrolCarTest, ShouldNotChangeGearInPetrolCarIfThatGearNotExist) {
    EXPECT_THROW(petrolCarTest.changeGear(-2), InvalidGear);
    EXPECT_THROW(petrolCarTest.changeGear(gears+1), InvalidGear);
}

TEST_F(PetrolCarTest, ShouldNotChangeGearToReverseFrom3){
    petrolCarTest.changeGear(3);
    EXPECT_THROW(petrolCarTest.changeGear(-1), InvalidGear);
}
