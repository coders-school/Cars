#include <gtest/gtest.h>
#include "PetrolEngine.hpp"

struct PetrolEngineTest : public ::testing::Test {
    // GIVEN
    PetrolEngine engine = PetrolEngine(150, 1993.0, 5);
};

TEST_F(PetrolEngineTest, shouldThrowException)
{
    // WHEN
    EXPECT_THROW(engine.changeGear(120), InvalidGear);
    EXPECT_THROW(engine.changeGear(-5), InvalidGear);
    engine.changeGear(-1);
    EXPECT_THROW(engine.changeGear(1), InvalidGear);
    engine.changeGear(0);
    engine.changeGear(2);
    EXPECT_THROW(engine.changeGear(-1), InvalidGear);
}

TEST_F(PetrolEngineTest, shouldNotThrowException)
{
    // WHEN
    EXPECT_NO_THROW(engine.changeGear(1));
    EXPECT_NO_THROW(engine.changeGear(0));
    EXPECT_NO_THROW(engine.changeGear(-1));
    EXPECT_NO_THROW(engine.changeGear(0));
    EXPECT_NO_THROW(engine.changeGear(1));
    EXPECT_NO_THROW(engine.changeGear(2));
    EXPECT_NO_THROW(engine.changeGear(4));
}

TEST_F(PetrolEngineTest, shouldChangeGear)
{
    // WHEN
    engine.changeGear(5);

    // THEN
    EXPECT_EQ(engine.getGear(), 5);
}

TEST_F(PetrolEngineTest, shouldInitPowerAndCapacity)
{
    // THEN
    EXPECT_EQ(engine.getPower(), 150);
    EXPECT_EQ(engine.getCapacity(), 1993.0);
}