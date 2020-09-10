#include <gtest/gtest.h>
#include "PetrolCar.hpp"
#include "PetrolEngine.hpp"

TEST(CarTest, TestingPetrolCar) {
    //GIVEN
    PetrolCar opel(std::make_unique<PetrolEngine>(120, 1800, 6));
    //WHEN
    //THEN
}
