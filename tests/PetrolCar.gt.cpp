#include "gtest/gtest.h"
#include "PetrolCar.hpp"
#include "SpeedException.hpp"
#include "GearException.hpp"

constexpr int power = 200;
constexpr int capacity = 2000;
constexpr int maxGears = 6;

constexpr short NEUTRAL_GEAR = 0;
constexpr short REAR_GEAR = -1;

struct PetrolCarTest: testing::Test{
    PetrolCar petrolCar{std::make_unique<PetrolEngine>(power, capacity, maxGears)};
};

TEST_F(PetrolCarTest, shouldAccelerateTo100){
    petrolCar.accelerate(100);
    ASSERT_EQ(petrolCar.getCurrentSpeed(), 100);
}

TEST_F(PetrolCarTest, shouldThrowSpeedExceptionWhenAcceleratingToNegativeNumberOrOverMaxSpeed){
    EXPECT_THROW(petrolCar.accelerate(-100), SpeedException);
    EXPECT_THROW(petrolCar.accelerate(petrolCar.getMaxSpeed() + 100), SpeedException);
}

TEST_F(PetrolCarTest, shouldChangeSpeedTo0){
    petrolCar.brake();
    ASSERT_EQ(petrolCar.getCurrentSpeed(), 0);
}

TEST_F(PetrolCarTest, shouldThrowExceptionWhenChangingGearToNegativeNumber){
    EXPECT_THROW(petrolCar.changeGear(-2), GearException);
}

TEST_F(PetrolCarTest, shouldThrowExceptionWhenChangingGearToInvalidOne){
    EXPECT_THROW(petrolCar.changeGear(petrolCar.engine_->getNumberOfGears() + 1), GearException);
}

TEST_F(PetrolCarTest, shouldThrowExceptionWhenChangingGearTo2or3){
    petrolCar.changeGear(1);
    EXPECT_THROW(petrolCar.changeGear(6), GearException);
    EXPECT_THROW(petrolCar.changeGear(5), GearException);
}

TEST_F(PetrolCarTest, shouldNotThrowExceptionWhenChangingGearTo3){
    EXPECT_NO_THROW(petrolCar.changeGear(2));
}