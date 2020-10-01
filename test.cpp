
#include "gtest/gtest.h"


struct Test : public ::testing::Test
{
    std::string some_string = "...";
};

TEST_F(Test, BoardShouldDoSomething)
{

    EXPECT_EQ(some_string, "...");
}



