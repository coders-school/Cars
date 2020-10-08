#include "Car.hpp"
#include "ElectricCar.hpp"
#include "ElectricEngine.hpp"
#include "HybridCar.hpp"
#include "PetrolCar.hpp"
#include "exceptions.hpp"

#include "gtest/gtest.h"

class CarsTest : public ::testing::Test {
protected:
    CarsTest()
        : electricCar_(std::make_shared<ElectricEngine>(130, 650)),
          petrolCar_(std::make_shared<PetrolEngine>(120, 1600, 6)),
          hybridCar_(std::make_shared<PetrolEngine>(150, 700, 5),
                     std::make_shared<ElectricEngine>(150, 600)) {}

    ElectricCar electricCar_;
    PetrolCar petrolCar_;
    HybridCar hybridCar_;
};

TEST_F(CarsTest, PetrolCarThrowRearGearExceptionWhenChangeFrom4ToMinus1) {
    auto engine = petrolCar_.getPetrolEngine();
    engine->changeGear(2);
    ASSERT_THROW(engine->changeGear(-1), RearGearChangeException);
}

TEST_F(CarsTest, PetrolCarThrowInvalidGearExceptionIfGearOutOfRange) {
    ASSERT_THROW(petrolCar_.getPetrolEngine()->changeGear(8), InvalidGearRangeException);
    ASSERT_THROW(petrolCar_.getPetrolEngine()->changeGear(-2), InvalidGearRangeException);
}

TEST_F(CarsTest, ElectricCarChangingEngineDuringRideIsImpossible) {
    /*
      I know that this test is quite poor (implementation testing) I just want to
       Check gtest capabilities of checking captured stdout
     */
    electricCar_.accelerate(80);
    testing::internal::CaptureStdout();
    electricCar_.setElectricEngine(std::make_shared<ElectricEngine>(100, 500));
    ASSERT_EQ("ElectricEngine\nYou cannot change engine during the ride!\n",
              testing::internal::GetCapturedStdout());
}

TEST_F(CarsTest, ElectricCarIsImpossibleToAccelerateToNegativeValue) {
    ASSERT_EQ(electricCar_.getSpeed(), 0);
    electricCar_.accelerate(-80);
    ASSERT_EQ(electricCar_.getSpeed(), 0);
}

TEST_F(CarsTest, HybridCarHasBothEngines) {
    ASSERT_TRUE(hybridCar_.getElectricEngine());
    ASSERT_TRUE(hybridCar_.getPetrolEngine());
}
