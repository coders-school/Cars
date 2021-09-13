#include "PetrolEngine.hpp"
#include "gtest/gtest.h"

TEST(PetrolEngineTest, InvalidGearShouldThrowExceptionOfOverflow) {
    PetrolEngine engine(60, 120, 5);
    EXPECT_THROW(engine.changeGear(6), InvalidGear);
}
TEST(PetrolEngineTest, TestShouldChangeGearToGearThreeShouldWorkNormally) {
    PetrolEngine engine(60, 120, 5);
    engine.changeGear(3);
    EXPECT_EQ(3, engine.getCurrentGear());
}

TEST(PetrolEngineTest, TestReverseGearShouldWorkNormally) {
    PetrolEngine engine(60, 120, 5);
    engine.changeGear(-1);
    EXPECT_EQ(-1, engine.getCurrentGear());
}
TEST(PetrolEngineTest, TestReverseGearShouldThrowException) {
    PetrolEngine engine(60, 120, 5);
    engine.changeGear(3);
    EXPECT_THROW(engine.changeGear(-1), InvalidGear);
}