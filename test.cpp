#include <gtest/gtest.h>

#include "PetrolEngine.hpp"

TEST(PetrolEngineMoreReverseGearTest,
     GivenCreatePetrolEngineAndSetGearToNeutralWhenTryToChangeGearLowerThanNegativeOneThenThrowInvalidGearException) {
    auto petrolEngine = PetrolEngine(143, 1992, 5);
    EXPECT_NO_THROW(petrolEngine.changeGear(0));

    try {
        petrolEngine.changeGear(-2);
    } catch (InvalidGear const& err) {
        EXPECT_EQ(std::string("Gear can't be less than -1"), err.what());
    } catch (...) {
        FAIL() << "Expected InvalidGear Exception";
    }

    try {
        petrolEngine.changeGear(-5);
    } catch (InvalidGear const& err) {
        EXPECT_EQ(std::string("Gear can't be less than -1"), err.what());
    } catch (...) {
        FAIL() << "Expected InvalidGear Exception";
    }
}

TEST(PetrolEngineReverseGearTest,
     GivenCreatePetrolEngineAndSetGearToPositiveWhenTryToChangeGearToReverseThenThrowInvalidGearException) {
    auto petrolEngine = PetrolEngine(143, 1992, 5);

    EXPECT_NO_THROW(petrolEngine.changeGear(2));
    try {
        petrolEngine.changeGear(-1);
    } catch (InvalidGear const& err) {
        EXPECT_EQ(std::string("Can't change gear to reverse from gear greater than 1"), err.what());
    } catch (...) {
        FAIL() << "Expected InvalidGear Exception";
    }

    EXPECT_NO_THROW(petrolEngine.changeGear(3));
    try {
        petrolEngine.changeGear(-1);
    } catch (InvalidGear const& err) {
        EXPECT_EQ(std::string("Can't change gear to reverse from gear greater than 1"), err.what());
    } catch (...) {
        FAIL() << "Expected InvalidGear Exception";
    }

    EXPECT_NO_THROW(petrolEngine.changeGear(5));
    try {
        petrolEngine.changeGear(-1);
    } catch (InvalidGear const& err) {
        EXPECT_EQ(std::string("Can't change gear to reverse from gear greater than 1"), err.what());
    } catch (...) {
        FAIL() << "Expected InvalidGear Exception";
    }
}

TEST(PetrolEngineTooMuchGearTest,
     GivenCreatePetrolEngineAndSetGearToNeutralWhenTryToChangeGearGreaterThanMaximumGearThenThrowInvalidGearException) {
    auto petrolEngine = PetrolEngine(143, 1992, 5);
    EXPECT_NO_THROW(petrolEngine.changeGear(0));

    try {
        petrolEngine.changeGear(6);
    } catch (InvalidGear const& err) {
        EXPECT_EQ(std::string("Gear can't be greater than 5"), err.what());
    } catch (...) {
        FAIL() << "Expected InvalidGear Exception";
    }

    try {
        petrolEngine.changeGear(14);
    } catch (InvalidGear const& err) {
        EXPECT_EQ(std::string("Gear can't be greater than 5"), err.what());
    } catch (...) {
        FAIL() << "Expected InvalidGear Exception";
    }
}

TEST(PetrolEngineTooMuchGearTest,
     GivenCreatePetrolEngineAndSetGearToNeutralWhenChangeGearInRangeThanExpectNoThrowException) {
    auto petrolEngine = PetrolEngine(143, 1992, 5);
    EXPECT_NO_THROW(petrolEngine.changeGear(5));
    EXPECT_NO_THROW(petrolEngine.changeGear(4));
    EXPECT_NO_THROW(petrolEngine.changeGear(3));
    EXPECT_NO_THROW(petrolEngine.changeGear(2));
    EXPECT_NO_THROW(petrolEngine.changeGear(1));
    EXPECT_NO_THROW(petrolEngine.changeGear(0));
    EXPECT_NO_THROW(petrolEngine.changeGear(-1));
    EXPECT_NO_THROW(petrolEngine.changeGear(1));
    EXPECT_NO_THROW(petrolEngine.changeGear(2));
    EXPECT_NO_THROW(petrolEngine.changeGear(5));
    EXPECT_NO_THROW(petrolEngine.changeGear(3));
    EXPECT_NO_THROW(petrolEngine.changeGear(0));
    EXPECT_NO_THROW(petrolEngine.changeGear(5));
    EXPECT_NO_THROW(petrolEngine.changeGear(0));
}
