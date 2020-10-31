#include <gtest/gtest.h>
#include <memory>
#include "Car.hpp"
#include "HybridCar.hpp"
#include "InvalidsError.hpp"

constexpr int power_petrol = 200;
constexpr float capacity_petrol = 100;
constexpr int gears = 6;
constexpr int currentGear = 0;

constexpr int power_electric = 150;
constexpr float capacity_electric = 120;

class HybridCarTest : public ::testing::Test {
protected:
    HybridCar hybridCarTest{std::make_unique<PetrolEngine>(power_petrol, capacity_petrol, gears),
                            std::make_unique<ElectricEngine>(power_electric, capacity_electric)};
};

TEST_F(HybridCarTest, TestOfAccelerate) {
    hybridCarTest.accelerate(70);
    ASSERT_EQ(hybridCarTest.getSpeed(), 70);
}

TEST_F(HybridCarTest, TestOfNegateiveAccelerateException) {
    EXPECT_THROW(hybridCarTest.accelerate(-700), InvalidSpeed);
}

TEST_F(HybridCarTest, TestOfChangePetrolEngineWhenCarIsDrive) {
    hybridCarTest.accelerate(120);
    EXPECT_THROW(hybridCarTest.changeEngine(std::make_unique<ElectricEngine>(120, 110),
                                            std::make_unique<PetrolEngine>(120, 110, 5)),
                 InvalidEngine);
}

TEST_F(HybridCarTest, TestOfChangePetrolEngineWhenCarIsStopped) {
    hybridCarTest.brake();
    EXPECT_NO_THROW(hybridCarTest.changeEngine(std::make_unique<ElectricEngine>(120, 110),
                                               std::make_unique<PetrolEngine>(120, 110, 5)));
}
