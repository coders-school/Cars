#include "gtest/gtest.h"
#include "Car.hpp"
#include "PetrolCar.hpp"
#include "ElectricCar.hpp"
#include "HybridCar.hpp"


// Tests throwing std::range_error when accelerate to speed = 350 is invoked
TEST(ElectricCarClasslTest, ShouldThrowRangeError) {
    ElectricCar nissan(std::make_unique<ElectricEngine>(130, 650));
    EXPECT_THROW(nissan.accelerate(300), std::range_error);
}

// Tests throwing std::range_error when accelerate to speed = 350 is invoked
// TEST(ElectricCarClasslTest, ShouldThrowRangeError) {
//     ElectricCar nissan(std::make_unique<ElectricEngine>(130, 650));
//     //EXPECT_THROW(nissan.changeEngine(std::make_unique<PetrolEngine>(150, 700, 7)), std::invalid_argument);
// }

// TEST(PetrolCarClasslTest, ShouldThrowRangeError) {
//     PetrolCar opel(std::make_unique<PetrolEngine>(120, 1800, 6));
//     EXPECT_THROW(opel.accelerate(350), std::range_error);
// }