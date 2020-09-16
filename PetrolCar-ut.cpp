#include <memory>
#include "ElectricEngine.hpp"
#include "ExceptionsClass.hpp"
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

TEST_F(PetrolCarTest, ShouldChangeEngineIfCarIsStopped) {
    petrolCar.brake();
    EXPECT_NO_THROW(petrolCar.changeEngine(std::make_unique<PetrolEngine>(100, 100, 5)));
}

TEST_F(PetrolCarTest, ShouldNotChangeEngineIfCarIsNotStopped) {
    petrolCar.accelerate(100);
    EXPECT_THROW(petrolCar.changeEngine(std::make_unique<PetrolEngine>(100, 100, 5)), InvalidChangeEngine);
}

TEST_F(PetrolCarTest, ChangeEngineShouldSwapEngines) {
    petrolCar.accelerate(0);
    auto newEngine = std::make_unique<PetrolEngine>(20, 20, 1); // one gear
    auto oldEngine = petrolCar.changeEngine(std::move(newEngine)); // four gears
    // throw exception when change gear to 3 (new engine has only one gear)
    EXPECT_THROW(petrolCar.changeGear(GearBox::third), InvalidGear);
    newEngine = petrolCar.changeEngine(std::move(oldEngine));
    // no throw exception when change gear to 3, because now car has old engine with four gear
    EXPECT_NO_THROW(petrolCar.changeGear(GearBox::third));
}
