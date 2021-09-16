#include "Engine.hpp"
#include <iostream>

class Car;

Engine::Engine(HorsePower power)
    : power_(power) {
    std::cout << __FUNCTION__ << std::endl;
}

bool Engine::attach(const Car* const ptr) {
    if (car_ != nullptr) {
        std::cout << "Detach engine first before attaching it to another car\n";
        return false;
    }
    if (ptr == nullptr) {
        std::cout << "Tried to attach engine to a not valid car\n";
        return false;
    }
    car_ = ptr;
    return true;
}

void Engine::detach() {
    car_ = nullptr;
}
