#include "PetrolCar.hpp"
#include "ElectricCar.hpp"
#include "HybridCar.hpp"
#include <iostream>

int main()
{
    Car* car = nullptr;
    std::cout << std::endl << "OPEL" << std::endl;
    PetrolCar opel(new PetrolEngine(120, 1800, 6));
    car = &opel;
    car -> accelerate(50);
    car ->brake();
    car ->accelerate(-900);
    auto hc = dynamic_cast<PetrolCar*>(car);
    if(hc)
        hc ->refuel();

    std::cout << std::endl << "NISSAN" << std::endl;
    ElectricCar nissan(new ElectricEngine(130, 650));
    nissan.charge();
    nissan.accelerate(80);
    nissan.engine_ = new ElectricEngine(150, 700);  // Changing an engine during driving is not safe
    nissan.turnLeft();

    std::cout << std::endl << "TOYOTA" << std::endl;
    HybridCar toyota(new PetrolEngine(80, 1400, 5), new ElectricEngine(100, 540));
    toyota.accelerate(100);
    toyota.brake();
    toyota.charge();
    toyota.refuel();
}
