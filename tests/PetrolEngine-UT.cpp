#include "CarExceptions.hpp"
#include "PetrolEngine.hpp"

#include "gtest/gtest.h"

namespace {
using testing::Combine;
using testing::Test;
using testing::TestWithParam;
using testing::ValuesIn;
}   // namespace

class PetrolEngineShould : public Test
{
  public:
    PetrolEngineShould()
        : genericEngine_(120, 1398, 5)
    {
    }

  protected:
    PetrolEngine genericEngine_;
};

class ChangingGearTests : public TestWithParam<std::tuple<int, int>>
{
  public:
    ChangingGearTests()
        : genericEngine_(120, 1398, 5)
    { }

  protected:
    PetrolEngine genericEngine_;
};

const std::vector<int> non_reverse_gears { 0, 1, 2, 3, 4, 5 };

INSTANTIATE_TEST_SUITE_P(AllowedGearChanges,
                         ChangingGearTests,
                         Combine(ValuesIn(non_reverse_gears), ValuesIn(non_reverse_gears)));

TEST_F(PetrolEngineShould, throwOnAttemptToSwitchToGearOutOfRangeOfPossibleOnes)
{
    std::vector<int> out_of_range_gears { -2, 8, -4, 6, 7, 8, 9 };
    for (auto gear : out_of_range_gears) {
        EXPECT_THROW(genericEngine_.changeGear(gear), InvalidGear);
    }
}

TEST_F(PetrolEngineShould, throwOnAttemptToSwitchToReverseFromOtherThanNeutral)
{
    std::vector<int> other_than_neutral { 1, 2, 3, 4, 5 };
    for (auto gear : other_than_neutral) {
        genericEngine_.changeGear(gear);
        EXPECT_THROW(genericEngine_.changeGear(-1), InvalidGear);
    }
}

TEST_F(PetrolEngineShould, throwOnAttemptToSwitchFromReverseToOtherThanNeutral)
{
    std::vector<int> other_than_neutral { 1, 2, 3, 4, 5 };
    for (auto gear : other_than_neutral) {
        genericEngine_.changeGear(-1);
        EXPECT_THROW(genericEngine_.changeGear(gear), InvalidGear);
    }
}

TEST_F(PetrolEngineShould, notThrowOnAttemptToSwitchFromReverseToNeutralAndTheOtherWay)
{
    // NOTE: genericEngine is by default should be initialized to neutral (0)
    EXPECT_NO_THROW(genericEngine_.changeGear(-1));
    EXPECT_NO_THROW(genericEngine_.changeGear(0));
}

TEST_P(ChangingGearTests, shouldNotThrow)
{
    auto [from_gear, to_gear] = GetParam();
    genericEngine_.changeGear(from_gear);
    EXPECT_NO_THROW(genericEngine_.changeGear(to_gear));
}