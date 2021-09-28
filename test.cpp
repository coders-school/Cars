#include "ElectricCar.hpp"
#include "HybridCar.hpp"
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
    EXPECT_THROW(ElectricCar Car(std::make_unique<ElectricEngine>(-12, 180)), std::invalid_argument);
    EXPECT_THROW(ElectricCar Car(std::make_unique<ElectricEngine>(-12, -1)), std::invalid_argument);
    EXPECT_NO_THROW(ElectricCar Car(std::make_unique<ElectricEngine>(5, 180)));
}

TEST(PetrolEngine, parameterTestInTheConstructor) {
    EXPECT_THROW(PetrolCar Car(std::make_unique<PetrolEngine>(-1, 18, 4)), std::invalid_argument);
    EXPECT_THROW(PetrolCar Car(std::make_unique<PetrolEngine>(0, 9, 6)), std::invalid_argument);
    EXPECT_NO_THROW(PetrolCar Car(std::make_unique<PetrolEngine>(10, 19, 5)));
}

TEST(HybridEngine, parameterTestInTheConstructor) {
    EXPECT_THROW(HybridCar Audi(std::make_unique<PetrolEngine>(0, 4, 9), std::make_unique<ElectricEngine>(12, 180)), std::invalid_argument);
    EXPECT_THROW(HybridCar Audi(std::make_unique<PetrolEngine>(0, 4, 5), std::make_unique<ElectricEngine>(-12, 180)), std::invalid_argument);
    EXPECT_THROW(HybridCar Audi(std::make_unique<PetrolEngine>(0, 4, 8), std::make_unique<ElectricEngine>(12, -180)), std::invalid_argument);
    EXPECT_NO_THROW(HybridCar Audi(std::make_unique<PetrolEngine>(2, 4, 5), std::make_unique<ElectricEngine>(12, 180)));
}
