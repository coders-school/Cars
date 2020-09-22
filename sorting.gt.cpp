#include "gtest/gtest.h"

TEST(FooTest, shouldReturnTrue){
	ASSERT_TRUE(false);
}

TEST(FooTest, shouldReturnFalse){
	ASSERT_FALSE(true);
}
