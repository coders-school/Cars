#include <gtest/gtest.h>
#include "PetrolCar.hpp"
#include "PetrolEngine.hpp"

TEST(CarTest, TestingPetrolCar) {
    //GIVEN
    PetrolCar opel(new PetrolEngine(120, 1800, 6));
    //WHEN
    //THEN
}