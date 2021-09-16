#include <iostream>
#include <memory>
#include "Car.hpp"
#include "ElectricCar.hpp"
#include "HybridCar.hpp"
#include "PetrolCar.hpp"
#include "PetrolEngine.hpp"

int main() {
    std::cout << std::endl
              << "OPEL" << std::endl;
    PetrolCar opel(std::make_unique<PetrolEngine>(Engine::HorsePower(120),
                                                  PetrolEngine::CubicCentimetre(1800),
                                                  PetrolEngine::Gear(6)));
    Car* car = &opel;
    car->accelerate(50);
    car->brake();
    car->accelerate(-900);
    car->refill();
    // car->changeEngine(new PetrolEngine(150, 700, 7));

    std::cout << std::endl
              << "NISSAN" << std::endl;
    ElectricCar nissan(std::make_unique<ElectricEngine>(Engine::HorsePower(130), ElectricEngine::AmpereHour(650)));
    car = &nissan;
    car->refill();
    car->accelerate(80);
    // nissan.engine_ = new ElectricEngine(150, 700);  // Changing an engine during driving is not safe
    // car->changeEngine(new ElectricEngine(150, 700));
    car->turnLeft();

    std::cout << std::endl
              << "TOYOTA" << std::endl;
    HybridCar toyota(std::make_unique<PetrolEngine>(Engine::HorsePower(80),
                                                    PetrolEngine::CubicCentimetre(1400),
                                                    PetrolEngine::Gear(5)),
                     std::make_unique<ElectricEngine>(Engine::HorsePower(100),
                                                      ElectricEngine::AmpereHour(540)));
    car = &toyota;
    car->accelerate(100);
    car->brake();
    car->refill();
}
