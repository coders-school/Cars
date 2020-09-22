#include "gtest/gtest.h"
#include "SpeedException.hpp"
#include "ElectricCar.hpp"

constexpr int power = 200;
constexpr int batteryCapacity = 4000;

struct ElectricCarTest: testing::Test{
    ElectricCar electricCar{std::make_unique<ElectricEngine>(power, batteryCapacity)};
};

TEST_F(ElectricCarTest, shouldAccelerateTo100){
    electricCar.accelerate(100);
    ASSERT_EQ(electricCar.getCurrentSpeed(), 100);
}

TEST_F(ElectricCarTest, shouldThrowSpeedExceptionWhenAcceleratingToNegativeNumberOrOverMaxSpeed){
    EXPECT_THROW(electricCar.accelerate(-100), SpeedException);
    EXPECT_THROW(electricCar.accelerate(electricCar.getMaxSpeed() + 100), SpeedException);
}

TEST_F(ElectricCarTest, shouldThrowSpeedExceptionWhenChangingEngineWhileCarIsDriving){
    electricCar.accelerate(100);
    EXPECT_THROW(electricCar.changeEngine(std::make_unique<ElectricEngine>(100, 2000)), SpeedException);
}

TEST_F(ElectricCarTest, shouldChangeSpeedTo0){
    electricCar.brake();
    ASSERT_EQ(electricCar.getCurrentSpeed(), 0);
}

TEST_F(ElectricCarTest, shouldNotThrowExceptionWhenChangingEngineWhileCarIsStopped){
    electricCar.brake();
    EXPECT_NO_THROW(electricCar.changeEngine(std::make_unique<ElectricEngine>(100, 2000)));
}