#include "Engine.hpp"

#include <iostream>

#include "Exceptions.hpp"

Engine::Engine(int power) : power_(power) {
    std::cout << __FUNCTION__ << '\n';
    if (power <= 0) {
        throw InvalidParameter("Cannot build engine with 0 or negative power.\n");
    }
    power_ = power;
}

Engine::~Engine() {
    std::cout << __FUNCTION__ << '\n';
}

int Engine::getPower() {
    return power_;
}
