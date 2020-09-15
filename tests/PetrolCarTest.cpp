#include <gtest/gtest.h>
#include "PetrolCar.hpp"

struct PetrolCarTest : ::testing::Test {
    PetrolCar car{new PetrolEngine{HorsePower(300), CubicCentimetre(3000), Gear(6)}, Litre(70)};
};

TEST_F(PetrolCarTest, startingTankCapacityShouldBeMax) {
    EXPECT_EQ(car.getCurrentTankCapacity().value_, car.getMaxTankCapacity().value_);
}

TEST_F(PetrolCarTest, restoreShouldSetCurrentTankCapacityToMax) {
    auto expectedValue = car.getMaxTankCapacity();
    car.restore();
    EXPECT_EQ(expectedValue.value_, car.getCurrentTankCapacity().value_);
}
