#include "ElectricCar.hpp"
#include "Invalidgear.hpp"
#include "PetrolCar.hpp"
#include "PetrolEngine.hpp"
#include "gtest/gtest.h"

TEST(changeGearTest, checksIfTheGearChangesAreCorrect) {
    int currentGear = 1;
    PetrolCar Car(std::make_unique<PetrolEngine>(120, 1800, 5));
    Car.getPetrolEngine()->setCurrentGear(3);

    EXPECT_THROW(Car.getPetrolEngine()->correctnessOfTheGearChange(5), InvalidGear);
    EXPECT_THROW(Car.getPetrolEngine()->correctnessOfTheGearChange(1), InvalidGear);
    EXPECT_THROW(Car.getPetrolEngine()->correctnessOfTheGearChange(-1), InvalidGear);
    EXPECT_THROW(Car.getPetrolEngine()->correctnessOfTheGearChange(0), InvalidGear);
    EXPECT_NO_THROW(Car.getPetrolEngine()->correctnessOfTheGearChange(4));
    EXPECT_NO_THROW(Car.getPetrolEngine()->correctnessOfTheGearChange(2));
}

TEST(ElectricEngine, parameterTestInTheConstructor) {
    ElectricCar Car(std::make_unique<ElectricEngine>(5, 180));

    EXPECT_THROW(Car.getElectricEngine()->ConstructorDataTest(-1, 2), std::invalid_argument);
    EXPECT_THROW(Car.getElectricEngine()->ConstructorDataTest(1, -2), std::invalid_argument);
    EXPECT_NO_THROW(Car.getElectricEngine()->ConstructorDataTest(1, 2));
}

TEST(PetrolEngine, parameterTestInTheConstructor) {
    PetrolCar Car(std::make_unique<PetrolEngine>(10, 19, 5));

    EXPECT_THROW(Car.getPetrolEngine()->TestConstructorData(2, 3, 9), std::invalid_argument);
    EXPECT_THROW(Car.getPetrolEngine()->TestConstructorData(-1, 3, 5), std::invalid_argument);
    EXPECT_NO_THROW(Car.getPetrolEngine()->TestConstructorData(1, 3, 5));
}
