#include <gtest/gtest.h>
#include "PetrolEngine.hpp"
#include "InvalidGear.hpp"

TEST(HelloTest, BasicAssertions) 
{
  EXPECT_STRNE("hello", "world");

  EXPECT_EQ(7 * 6, 42);
}

TEST(CarsTests, ShouldThrowInvalidGear) 
{
    PetrolEngine testEngine(150, 700, 7);
    testEngine.changeGear(5);
    EXPECT_THROW(testEngine.changeGear(-1), InvalidGear);
}