#include <iostream>
#include <memory>
#include "ElectricCar.hpp"
#include "HybridCar.hpp"
#include "PetrolCar.hpp"

int main() {
    std::cout << std::endl
              << "OPEL" << std::endl;
    PetrolCar opel(std::make_unique<PetrolEngine>(Engine::HorsePower(120), PetrolEngine::CubicCentimetre(1800), PetrolEngine::Gear(6)));
    opel.accelerate(50);
    opel.brake();
    opel.accelerate(-900);
    opel.refill();

    std::cout << std::endl
              << "NISSAN" << std::endl;
    ElectricCar nissan(std::make_unique<ElectricEngine>(Engine::HorsePower(130), ElectricEngine::AmpereHour(650)));
    nissan.refill();
    nissan.accelerate(80);
    nissan.turnLeft();

    std::cout << std::endl
              << "TOYOTA" << std::endl;
    HybridCar toyota(std::make_unique<PetrolEngine>(Engine::HorsePower(80), PetrolEngine::CubicCentimetre(1400), PetrolEngine::Gear(5)),
                     std::make_unique<ElectricEngine>(Engine::HorsePower(100), ElectricEngine::AmpereHour(540)));
    toyota.accelerate(100);
    toyota.brake();
    toyota.refill();
}
