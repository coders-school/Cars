
#include <memory>
#include "ElectricCar.hpp"
#include "HybridCar.hpp"
#include "PetrolCar.hpp"
#include "gtest/gtest.h"

TEST(ExceptionsTest, ShouldThrowExceptionWhenChangeFromNotNeutralGearToReverseGear) {
    HybridCar toyota(std::make_shared<PetrolEngine>(80, 1400, 5), std::make_shared<ElectricEngine>(100, 540));
    toyota.changeGear(5);
    EXPECT_THROW(toyota.changeGear(-1), InvalidGear);
}

TEST(ExceptionsTest, ShouldNotThrowExceptionWhenChangeFromNeutralGearToReverseGear) {
    HybridCar toyota(std::make_shared<PetrolEngine>(80, 1400, 5), std::make_shared<ElectricEngine>(100, 540));
    toyota.changeGear(0);
    EXPECT_NO_THROW(toyota.changeGear(-1));
}

TEST(ExceptionsTest, ShouldThrowExceptionWhenChangeToUnavailableGear) {
    HybridCar toyota(std::make_shared<PetrolEngine>(80, 1400, 5), std::make_shared<ElectricEngine>(100, 540));
    toyota.changeGear(0);
    EXPECT_NO_THROW(toyota.changeGear(5));
    EXPECT_THROW(toyota.changeGear(6), InvalidGear);
}
