#include "HybridCar.hpp"
#include "gtest/gtest.h"

TEST(EngineTest, ShouldChangeGear) {
    // GIVEN
    PetrolEngine engine{ 100, 1900, 5};

    // WHEN: properly changed
    // THEN
    EXPECT_NO_THROW([&engine](){ engine.changeGear(1); }());
    EXPECT_NO_THROW([&engine](){ engine.changeGear(2); }());
    EXPECT_NO_THROW([&engine](){ engine.changeGear(3); }());
    EXPECT_NO_THROW([&engine](){ engine.changeGear(4); }());
    EXPECT_NO_THROW([&engine](){ engine.changeGear(5); }());
    EXPECT_NO_THROW([&engine](){ engine.changeGear(4); }());
    EXPECT_NO_THROW([&engine](){ engine.changeGear(3); }());
    EXPECT_NO_THROW([&engine](){ engine.changeGear(2); }());
    EXPECT_NO_THROW([&engine](){ engine.changeGear(1); }());
    EXPECT_NO_THROW([&engine](){ engine.changeGear(0); }());
    EXPECT_NO_THROW([&engine](){ engine.changeGear(-1); }());
}

TEST(EngineTest, ShouldNotChangeGear)
{
    //GIVEN
    PetrolEngine engine{ 100, 1900, 5};

    // WHEN: incorrectly changed
    // THEN
    // WHEN: incorrectly changed
    // THEN
    EXPECT_THROW([&engine](){ engine.changeGear(-2);}(), InvalidGear);
    EXPECT_THROW([&engine](){ engine.changeGear(4);}(), InvalidGear);
    EXPECT_THROW([&engine](){ engine.changeGear(100);}(), InvalidGear);
    EXPECT_THROW([&engine](){ engine.changeGear(-10);}(), InvalidGear);
    EXPECT_THROW([&engine](){ engine.changeGear(1000);}(), InvalidGear);
    EXPECT_THROW([&engine](){ engine.changeGear(6);}(), InvalidGear);
    EXPECT_THROW([&engine](){ engine.changeGear(3);}(), InvalidGear);
}