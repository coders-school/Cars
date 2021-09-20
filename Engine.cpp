#include "Engine.hpp"

#include "InvalidParameter.hpp"

Engine::Engine(int power) {
    if (power <= 0) {
        throw InvalidParameter("> power cannot be negative!");
    }
    power_ = power;
}
