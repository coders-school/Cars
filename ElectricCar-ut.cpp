#include <memory>
#include "ElectricCar.hpp"
#include "ElectricEngine.hpp"
#include "ExceptionsClass.hpp"
#include "gtest/gtest.h"

namespace StartParameters {

constexpr uint16_t power = 100;
constexpr uint16_t capacity = 200;
constexpr int speed = 50;
}  // namespace StartParameters

struct ElectricCarTest : public ::testing::Test {
    ElectricCar electricCar{std::make_unique<ElectricEngine>(StartParameters::power,
                                                             StartParameters::capacity)};
};

TEST_F(ElectricCarTest, ShouldChangePetrolCarVelocity) {
    EXPECT_NO_THROW(electricCar.accelerate(100));
}

TEST_F(ElectricCarTest, ShouldNotAccelerateWhenSpeedIsLessThanZero) {
    EXPECT_THROW(electricCar.accelerate(-2), InvalidSpeed);
}

TEST_F(ElectricCarTest, ShouldNotChangeGearFromNeutralToRear) {
    //electrical car has not gearbox
    EXPECT_THROW(electricCar.changeGear(GearBox::neutral), InvalidGear);
    EXPECT_THROW(electricCar.changeGear(GearBox::rear), InvalidGear);
}

TEST_F(ElectricCarTest, ShouldNotChangeGearToFiveWhenGearsIsEqualThree) {
    EXPECT_THROW(electricCar.changeGear(GearBox::fifth), InvalidGear);
}

TEST_F(ElectricCarTest, ShouldChangeEngineIfCarIsStopped) {
    electricCar.brake();
    EXPECT_NO_THROW(electricCar.changeEngine(std::make_unique<ElectricEngine>(100, 100)));
}

TEST_F(ElectricCarTest, ShouldNotChangeEngineIfCarIsNotStopped) {
    electricCar.accelerate(100);
    EXPECT_THROW(electricCar.changeEngine(std::make_unique<ElectricEngine>(100, 100)), InvalidChangeEngine);
}
