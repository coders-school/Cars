#include <memory>
#include "ElectricEngine.hpp"
#include "InvalidGear.hpp"
#include "InvalidSpeed.hpp"
#include "PetrolCar.hpp"
#include "PetrolEngine.hpp"
#include "gtest/gtest.h"

namespace StartParameters {

constexpr uint16_t power = 100;
constexpr uint16_t capacity = 200;
constexpr uint8_t gears = 4;
constexpr int speed = 50;
}  // namespace StartParameters

struct PetrolCarTest : public ::testing::Test {
    PetrolCar petrolCar{std::make_unique<PetrolEngine>(StartParameters::power,
                                                       StartParameters::capacity,
                                                       StartParameters::gears)};
};

TEST_F(PetrolCarTest, ShouldChangePetrolCarVelocity) {
    EXPECT_NO_THROW(petrolCar.accelerate(100));
}

TEST_F(PetrolCarTest, ShouldNotAccelerateWhenSpeedIsLessThanZero) {
    EXPECT_THROW(petrolCar.accelerate(-2), InvalidSpeed);
}

TEST_F(PetrolCarTest, ShouldChangeGearFromNeutralToRear) {
    EXPECT_NO_THROW(petrolCar.changeGear(GearBox::neutral));
    EXPECT_NO_THROW(petrolCar.changeGear(GearBox::rear));
}

TEST_F(PetrolCarTest, ShouldNotChangeGearToFiveWhenGearsIsEqualThree) {
    EXPECT_THROW(petrolCar.changeGear(GearBox::fifth), InvalidGear);
}

TEST_F(PetrolCarTest, ShouldNotChangeGearFromThreeToRear) {
    EXPECT_NO_THROW(petrolCar.changeGear(GearBox::third));
    EXPECT_THROW(petrolCar.changeGear(GearBox::rear), InvalidGear);
}
