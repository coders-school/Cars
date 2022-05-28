#include <iostream>
#include "Car.hpp"
#include "ElectricCar.hpp"
#include "HybridCar.hpp"
#include "PetrolCar.hpp"

int main()
{

    std::cout << std::endl << "OPEL" << std::endl;
    PetrolCar opel(std::make_shared<PetrolEngine>(PetrolEngine(120, 1800, 6)));
    std::shared_ptr<Car> car = std::make_shared<PetrolCar>(opel);
    car->accelerate(50);
    car->brake();
    car->accelerate(-900);
    car->refill();
    // car->changeEngine(new PetrolEngine(150, 700, 7));

    std::cout << std::endl << "NISSAN" << std::endl;
    ElectricCar nissan(std::make_shared<ElectricEngine>(ElectricEngine(130, 650)));
    car = std::make_shared<ElectricCar>(nissan);
    car->refill();
    car->accelerate(80);
    // nissan.engine_ = new ElectricEngine(150, 700);  // Changing an engine during driving is not safe
    // car->changeEngine(new ElectricEngine(150, 700));
    car->turnLeft();

    std::cout << std::endl << "TOYOTA" << std::endl;
    HybridCar toyota(std::make_shared<PetrolEngine>(PetrolEngine(80, 1400, 5)), std::make_shared<ElectricEngine>(ElectricEngine(100, 540)));
    car = std::make_shared<HybridCar>(toyota);
    car->accelerate(100);
    car->brake();
    car->refill();
}
