#include <iostream>
#include <memory>
#include "Car.hpp"
#include "ElectricCar.hpp"
#include "HybridCar.hpp"
#include "PetrolCar.hpp"
#include "PetrolEngine.hpp"

int main() {
    std::cout << "\nOPEL\n";
    PetrolCar opel(std::make_unique<PetrolEngine>(Engine::HorsePower(120),
                                                  PetrolEngine::CubicCentimetre(1800),
                                                  PetrolEngine::Gear(6)));
    Car* car = &opel;
    car->accelerate(50);
    car->brake();
    car->accelerate(-900);
    car->refill();
    car->changeEngine(std::make_unique<PetrolEngine>(Engine::HorsePower(150),
                                                     PetrolEngine::CubicCentimetre(700),
                                                     PetrolEngine::Gear(7)));

    std::cout << "\nNISSAN\n";
    ElectricCar nissan(std::make_unique<ElectricEngine>(Engine::HorsePower(130), ElectricEngine::AmpereHour(650)));
    car = &nissan;
    car->refill();
    car->accelerate(80);
    car->changeEngine(std::make_unique<ElectricEngine>(Engine::HorsePower(150), ElectricEngine::AmpereHour(700)));
    car->turnLeft();

    std::cout << "\nTOYOTA\n";
    HybridCar toyota(std::make_unique<PetrolEngine>(Engine::HorsePower(80),
                                                    PetrolEngine::CubicCentimetre(1400),
                                                    PetrolEngine::Gear(5)),
                     std::make_unique<ElectricEngine>(Engine::HorsePower(100),
                                                      ElectricEngine::AmpereHour(540)));
    car = &toyota;
    car->accelerate(100);
    car->brake();
    car->refill();
    car->changeEngine(std::make_unique<ElectricEngine>(Engine::HorsePower(150), ElectricEngine::AmpereHour(700)));
    car->changeEngine(std::make_unique<PetrolEngine>(Engine::HorsePower(150),
                                                     PetrolEngine::CubicCentimetre(700),
                                                     PetrolEngine::Gear(7)));
}
