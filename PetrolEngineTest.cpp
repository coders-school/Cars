#include <gtest/gtest.h>
#include "PetrolEngine.hpp"

struct PetrolEngineTest : public ::testing::Test {
    //GIVEN
    PetrolEngine engine = PetrolEngine(150, 1993.0, 5);
};

TEST_F(PetrolEngineTest, shouldThrowException) {
    //WHEN
    EXPECT_THROW(engine.changeGear(120), InvalidGear);
}
TEST_F(PetrolEngineTest, shouldNotThrowException) {
    //WHEN
    EXPECT_NO_THROW(engine.changeGear(1));
}
