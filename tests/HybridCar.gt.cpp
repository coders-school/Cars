#include <gtest/gtest.h>
#include "HybridCar.hpp"
#include "GearException.hpp"
#include "SpeedException.hpp"

constexpr int powerPetrol = 200;
constexpr float capacityPetrol = 100;
constexpr int maxGears = 6;

constexpr int powerElectric = 150;
constexpr float capacityElectric = 120;

class HybridCarTest : public ::testing::Test {
protected:
    HybridCar hybridCar{std::make_unique<PetrolEngine>(powerPetrol, capacityPetrol, maxGears),
                            std::make_unique<ElectricEngine>(powerElectric, capacityElectric)};
};

TEST_F(HybridCarTest, shouldAccelerateTo70) {
    hybridCar.accelerate(70);
    ASSERT_EQ(hybridCar.getCurrentSpeed(), 70);
}

TEST_F(HybridCarTest, shouldThrowSpeedExceptionWhenAcceleratingToNegativeNumber) {
    EXPECT_THROW(hybridCar.accelerate(-700), SpeedException);
}

TEST_F(HybridCarTest, shouldThrowSpeedExceptionWhenChangingPetrolEngineWhileCarIsDriving) {
    hybridCar.accelerate(120);
    EXPECT_THROW(hybridCar.changeEngine(std::make_unique<PetrolEngine>(120, 110, 5)), SpeedException);
}

TEST_F(HybridCarTest, shouldThrowSpeedExceptionWhenChangingElectricEngineWhileCarIsDriving) {
    hybridCar.accelerate(120);
    EXPECT_THROW(hybridCar.changeEngine(std::make_unique<ElectricEngine>(120, 110)), SpeedException);
}

TEST_F(HybridCarTest, shouldNotThrowSpeedExceptionWhenChangingElectricEngineWhileCarIsStopped) {
    hybridCar.brake();
    EXPECT_NO_THROW(hybridCar.changeEngine(std::make_unique<PetrolEngine>(120, 110, 5)));
}

TEST_F(HybridCarTest, shouldNotThrowSpeedExceptionWhenChangingPetrolEngineWhileCarIsStopped) {
    hybridCar.brake();
    EXPECT_NO_THROW(hybridCar.changeEngine(std::make_unique<ElectricEngine>(120, 110)));
}