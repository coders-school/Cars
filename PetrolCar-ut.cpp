#include <gtest/gtest.h>
#include "PetrolCar.hpp"

struct PetrolCarTest : ::testing::Test {
    PetrolCar opel = PetrolCar(new PetrolEngine(80, 1400, 5));
};


TEST_F(PetrolCarTest, checkAcceleration) {
    opel.accelerate(50);
    ASSERT_EQ(opel.getSpeed(), 50);
}
