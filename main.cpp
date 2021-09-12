#include <iostream>
#include "ElectricCar.hpp"
#include "HybridCar.hpp"
#include "PetrolCar.hpp"

int main() {
    std::cout << std::endl
              << "OPEL" << std::endl;
    PetrolCar opel(new PetrolEngine(Engine::HorsePower(120), 1800, 6));
    opel.accelerate(50);
    opel.brake();
    opel.accelerate(-900);
    opel.refill();

    std::cout << std::endl
              << "NISSAN" << std::endl;
    ElectricCar nissan(new ElectricEngine(Engine::HorsePower(130), 650));
    nissan.refill();
    nissan.accelerate(80);
    //nissan.engine_ = new ElectricEngine(150, 700);  // Changing an engine during driving is not safe
    nissan.turnLeft();

    std::cout << std::endl
              << "TOYOTA" << std::endl;
    HybridCar toyota(new PetrolEngine(Engine::HorsePower(80), 1400, 5), new ElectricEngine(Engine::HorsePower(100), 540));
    toyota.accelerate(100);
    toyota.brake();
    toyota.refill();
}
