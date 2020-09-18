#include <gtest/gtest.h>
#include "PetrolEngine.hpp"

constexpr int reverseGear = -1;
constexpr int neutralGear = 0;
constexpr int thirdGear = 3;
constexpr int fourthGear = 4;
constexpr int tooHighGear = 9;

TEST(PetrolEngineTest, CallingChangeGearShouldChangeGear){
    PetrolEngine engine(150, 300, 5);
    engine.changeGear(thirdGear);
    EXPECT_EQ(thirdGear, engine.getCurrentGear());
}

TEST(PetrolEngineTest, PassingReverseGearWhenHavingPositiveShouldThrowException){
    PetrolEngine engine(150, 300, 5);
    engine.changeGear(thirdGear);
    EXPECT_THROW(engine.changeGear(reverseGear), InvalidGearException);
}

TEST(PetrolEngineTest, PassingToHighGearShouldThrowException){
    PetrolEngine engine(150, 300, 5);
    EXPECT_THROW(engine.changeGear(tooHighGear), InvalidGearException);
}

TEST(PetrolEngineTest, PassingReverseGearDuringHavingNeutralShouldWork){
    PetrolEngine engine(150, 300, 5);
    engine.changeGear(reverseGear);
    EXPECT_EQ(reverseGear, engine.getCurrentGear());
}
