#include "gtest/gtest.h"
#include <memory>

#include "../PetrolEngine.hpp"

constexpr int powerValue = 150;
constexpr float capacityValue = 2.0;
constexpr int gearsValue = 5;
constexpr int reverseGear = -1;
constexpr int neutralGear = 0;
constexpr int invalidPositiveGear = 8;
constexpr int invalidNegativeGear = -2;
constexpr int correctGear = 3;

TEST(PetrolEngine, ChangeGearShouldSucceed)
{
    auto engine = std::make_unique<PetrolEngine>(powerValue, capacityValue, gearsValue);
    engine->changeGear(correctGear);
    EXPECT_EQ(engine->getCurrentGear(), correctGear);
}

TEST(PetrolEngine, ChangeGearWithInvalidPositiveGearShouldThrownException)
{
    auto engine = std::make_unique<PetrolEngine>(powerValue, capacityValue, gearsValue);
    EXPECT_THROW(engine->changeGear(invalidPositiveGear), InvalidGear);
}

TEST(PetrolEngine, ChangeGearWithInvalidNegativeGearShouldThrownException)
{
    auto engine = std::make_unique<PetrolEngine>(powerValue, capacityValue, gearsValue);
    EXPECT_THROW(engine->changeGear(invalidNegativeGear), InvalidGear);
}

TEST(PetrolEngine, ChangeGearToReverseShouldSucceed)
{
    auto engine = std::make_unique<PetrolEngine>(powerValue, capacityValue, gearsValue);
    EXPECT_EQ(engine->getCurrentGear(), neutralGear);
    engine->changeGear(reverseGear);
    EXPECT_EQ(engine->getCurrentGear(), reverseGear);
}

TEST(PetrolEngine, ChangeGearToReverseFromNotNeutralShouldThrownException)
{
    auto engine = std::make_unique<PetrolEngine>(powerValue, capacityValue, gearsValue);
    EXPECT_EQ(engine->getCurrentGear(), neutralGear);
    engine->changeGear(correctGear);
    EXPECT_EQ(engine->getCurrentGear(), correctGear);
    EXPECT_THROW(engine->changeGear(reverseGear), InvalidGear);
}
