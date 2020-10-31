#include <gtest/gtest.h>
#include "PetrolEngine.hpp"

constexpr int reverseGear = -1;
constexpr int neutralGear = 0;
constexpr int thirdGear = 3;
constexpr int fourthGear = 4;
constexpr int tooHighGear = 9;

constexpr int basicPower = 150;
constexpr int basicCapacity = 300;
constexpr int defaultNumberOfGears = 5;

class PetrolEngineTest : public ::testing::Test {
public:
    PetrolEngineTest()
        : engine(basicPower, basicCapacity, defaultNumberOfGears){}

    PetrolEngine engine;
};


TEST_F(PetrolEngineTest, CallingChangeGearShouldChangeGear){
    engine.changeGear(thirdGear);
    EXPECT_EQ(thirdGear, engine.getCurrentGear());
}

TEST_F(PetrolEngineTest, PassingReverseGearWhenHavingPositiveShouldThrowException){
    engine.changeGear(thirdGear);
    EXPECT_THROW(engine.changeGear(reverseGear), InvalidGearException);
}

TEST_F(PetrolEngineTest, PassingToHighGearShouldThrowException){
    EXPECT_THROW(engine.changeGear(tooHighGear), InvalidGearException);
}

TEST_F(PetrolEngineTest, PassingReverseGearDuringHavingNeutralShouldWork){
    engine.changeGear(reverseGear);
    EXPECT_EQ(reverseGear, engine.getCurrentGear());
}
