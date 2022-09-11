// TODO: VERIFY
#include "ElectricCar.hpp"
#include "HybridCar.hpp"
#include "PetrolCar.hpp"

#include <iostream>
#include <memory>

int main()
{
    std::cout << std::endl
              << "OPEL" << std::endl;
    std::unique_ptr<Car> opel = std::make_unique<PetrolCar>(PetrolEngine(120, 1800, 6));
    opel->accelerate(50);
    opel->brake();
    opel->accelerate(-900);
    opel->refill();

    std::cout << std::endl
              << "NISSAN" << std::endl;
    std::unique_ptr<Car> nissan = std::make_unique<ElectricCar>(ElectricEngine(130, 650));
    nissan->refill();
    nissan->accelerate(80);
    // nissan.engine_ = ElectricEngine(150, 700);  // Changing an engine during driving is not safe
    nissan->turnLeft();

    std::cout << std::endl
              << "TOYOTA" << std::endl;
    std::unique_ptr<Car> toyota = std::make_unique<HybridCar>(PetrolEngine(80, 1400, 5), ElectricEngine(100, 540));
    toyota->accelerate(100);
    toyota->brake();
    toyota->refill();
}
