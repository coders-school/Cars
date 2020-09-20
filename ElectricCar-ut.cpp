#include "gtest/gtest.h"

#include "ElectricCar.hpp"
#include "ElectricEngine.hpp"

struct ElectricCarTest : ::testing::Test {
    ElectricCar electricCar = ElectricCar(new ElectricEngine(120, 1800));
};
