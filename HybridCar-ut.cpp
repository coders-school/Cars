#include <memory>
#include "ElectricEngine.hpp"
#include "ExceptionsClass.hpp"
#include "HybridCar.hpp"
#include "PetrolEngine.hpp"
#include "gtest/gtest.h"

namespace StartParameters {

constexpr int petrolPower = 100;
constexpr int petrolCapacity = 200;
constexpr int petrolGears = 3;
constexpr int electricPower = 50;
constexpr int electricCapacity = 50;
constexpr int electricCurrentCapacity = 25;
constexpr int speed = 50;
}  // namespace StartParameters

struct HybridCarTest : public ::testing::Test {
    HybridCar hybridCar{std::make_unique<PetrolEngine>(StartParameters::petrolPower,
                                                       StartParameters::petrolCapacity,
                                                       StartParameters::petrolGears),
                        std::make_unique<ElectricEngine>(StartParameters::electricPower,
                                                         StartParameters::electricCapacity,
                                                         StartParameters::electricCurrentCapacity)};
};

TEST_F(HybridCarTest, ShouldChangeHybridCarVelocity) {
    EXPECT_NO_THROW(hybridCar.accelerate(100));
}

TEST_F(HybridCarTest, ShouldNotAccelerateWhenSpeedIsLessThanZero) {
    EXPECT_THROW(hybridCar.accelerate(-2), InvalidSpeed);
}

TEST_F(HybridCarTest, ShouldChangeGearFromNeutralToRear) {
    EXPECT_NO_THROW(hybridCar.changeGear(GearBox::neutral));
    EXPECT_NO_THROW(hybridCar.changeGear(GearBox::rear));
}

TEST_F(HybridCarTest, ShouldNotChangeGearToFiveWhenGearsIsEqualThree) {
    EXPECT_THROW(hybridCar.changeGear(GearBox::fifth), InvalidGear);
}

TEST_F(HybridCarTest, ShouldNotChangeGearFromThreeToRear) {
    EXPECT_NO_THROW(hybridCar.changeGear(GearBox::third));
    EXPECT_THROW(hybridCar.changeGear(GearBox::rear), InvalidGear);
}
