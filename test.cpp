#include "gtest/gtest.h"
#include "PetrolEngine.hpp"
#include "PetrolCar.hpp"
#include "Invalidgear.hpp"

TEST(changeGearTest,checksIfTheGearChangesAreCorrect){

int currentGear=1;
PetrolCar Car(std::make_unique<PetrolEngine>(120, 1800, 6));
Car.getPetrolEngine()->setCurrentGear(3);

EXPECT_THROW(Car.getPetrolEngine()->changeGear(5),InvalidGear);
EXPECT_THROW(Car.getPetrolEngine()->changeGear(1),InvalidGear);
EXPECT_THROW(Car.getPetrolEngine()->changeGear(1),InvalidGear);
EXPECT_THROW(Car.getPetrolEngine()->changeGear(0),InvalidGear);   
EXPECT_NO_THROW(Car.getPetrolEngine()->changeGear(4));
EXPECT_NO_THROW(Car.getPetrolEngine()->changeGear(3));
EXPECT_NO_THROW(Car.getPetrolEngine()->changeGear(2));
}
