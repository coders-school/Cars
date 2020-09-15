#include "Vehicle.hpp"
#include <iostream>
Vehicle::Vehicle() {
    std::cout << __FUNCTION__ << std::endl;
}

Vehicle::~Vehicle() {
    std::cout << __FUNCTION__ << std::endl;
}
