#include "Engine.hpp"

#include <iostream>

Engine::Engine(int power) : power_(power) {
    std::cout << __FUNCTION__ << '\n';
}

Engine::~Engine() {
    std::cout << __FUNCTION__ << '\n';
}

int Engine::getPower() {
    return power_;
}
