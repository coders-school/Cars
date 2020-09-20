#include "gtest/gtest.h"

#include "HybridCar.hpp"
#include "ElectricEngine.hpp"

struct HybridCarTest : ::testing::Test {
    HybridCar hybridCar = HybridCar(new PetrolEngine(120, 1800, 6), new ElectricEngine(120, 1800));
};
