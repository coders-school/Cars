#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>

#include "../PetrolCar.hpp"
#include "../PetrolEngine.hpp"

using namespace std;

void SetUp() {

};

TEST (Car, InitialSpeed) {
    PetrolCar TestCar(new PetrolEngine(100, 100, 6));
    EXPECT_EQ(TestCar.getCurrentSpeed(), 0);
};

TEST (Car, InitialGear) {
    PetrolCar TestCar(new PetrolEngine(100, 100, 6));
    EXPECT_EQ(TestCar.getCurrentGear(), "0");
}

TEST (Car, ChangeGearsSequence) {
    PetrolCar TestCar(new PetrolEngine(100, 100, 6));
    TestCar.changeGear(1);
    TestCar.changeGear(3);
    TestCar.changeGear(5);
    TestCar.changeGear(0);
    TestCar.changeGear("R");
    EXPECT_EQ(TestCar.getCurrentGear(), "R");
}

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}