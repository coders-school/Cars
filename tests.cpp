#include <gtest/gtest.h>
#include "PetrolEngine.hpp"
#include "InvalidGear.hpp"

struct PetrolEngineTest : ::testing::Test{
    PetrolEngine engine{
        120, 
        1800,
        6
    };
};

TEST_F(PetrolEngineTest, ExceptionEngineTest){
    EXPECT_THROW(engine.changeGear(-5), InvalidGear);
    EXPECT_THROW(engine.changeGear(30), InvalidGear);
    EXPECT_NO_THROW(engine.changeGear(1));
    EXPECT_NO_THROW(engine.changeGear(0));
    EXPECT_NO_THROW(engine.changeGear('R'));
    EXPECT_THROW(engine.changeGear(3), InvalidGear);
    EXPECT_NO_THROW(engine.changeGear(0));
}