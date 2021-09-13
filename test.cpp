#include "PetrolEngine.hpp"
#include "gtest/gtest.h"

TEST(PetrolEngineTest, InvalidGearShouldThrowExceptionOfOverflow) {
    PetrolEngine engine(60, 120, 5);
    EXPECT_THROW(engine.changeGear(6), InvalidGear);
}