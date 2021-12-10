#include <iostream>

#include "PetrolCar.hpp"
#include "ElectricCar.hpp"
#include "HybridCar.hpp"

int main()
{
    std::cout << std::endl
              << "OPEL" << std::endl;
    std::unique_ptr<Car> car = std::make_unique<PetrolCar>(std::make_unique<PetrolEngine>(120, 1800, 6));
    car->accelerate(50);
    car->brake();
    car->accelerate(-900);
    car->refill();

    std::cout << std::endl
              << "NISSAN" << std::endl;
    car.reset(new ElectricCar(std::make_unique<ElectricEngine>(130, 650)));
    car->refill();
    car->accelerate(80);
    // nissan.engine_ = new ElectricEngine(150, 700);  // Changing an engine during driving is not safe
    car->turnLeft();

    std::cout << std::endl
              << "TOYOTA" << std::endl;
    car.reset(new HybridCar(std::make_unique<PetrolEngine>(80, 1400, 5), std::make_unique<ElectricEngine>(100, 540)));
    car->accelerate(100);
    car->brake();
    car->refill();
}
