#include <gtest/gtest.h>
#include <stdexcept>
#include "PetrolEngine.hpp"

TEST(PetrolEngineTest, ValidGearChange) {
    PetrolEngine engine(500, 2, 7);
    
    EXPECT_EQ(engine.getCurrentGear(), 0);
    engine.changeGear(1);
    EXPECT_EQ(engine.getCurrentGear(), 1);
    engine.changeGear(2);
    EXPECT_EQ(engine.getCurrentGear(), 2);
    engine.changeGear(1);
    EXPECT_EQ(engine.getCurrentGear(), 1);
    engine.changeGear(-1);
    EXPECT_EQ(engine.getCurrentGear(), -1);
}

TEST(PetrolEngineTest, InvalidGearChange) {
    PetrolEngine engine(500, 2, 7);
    
    EXPECT_THROW(engine.changeGear(-2), InvalidGear);
    EXPECT_THROW(engine.changeGear(8), InvalidGear);
    EXPECT_THROW(engine.changeGear(9), InvalidGear);
    engine.changeGear(1);
    engine.changeGear(2);
    EXPECT_THROW(engine.changeGear(-1), InvalidGear);
    EXPECT_THROW(engine.changeGear(4), InvalidGear);

}