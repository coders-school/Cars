#include "Engine.hpp"
#include <iostream>

Engine::Engine(HorsePower power)
    : power_(power) {
    std::cout << __FUNCTION__ << std::endl;
}