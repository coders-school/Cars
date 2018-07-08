#include "PetrolCar.hpp"
#include "ElectricCar.hpp"
#include "HybridCar.hpp"

int main()
{
    ElectricCar nissan(new ElectricEngine(130, 650));
    PetrolCar opel(new PetrolEngine(120, 1800, 6));
    HybridCar toyota(new PetrolEngine(80, 1400, 5), new ElectricEngine(100, 540));

    Car* car = &opel;
    car->accelerate(50);
    car->brake();
    car->refill();
    //opel.refuel();

    car = &nissan;
    car->refill();
    car->accelerate(80);
    car->turnLeft();

    toyota.accelerate(100);
    toyota.ElectricCar::brake();
    //toyota.charge();
    //toyota.refuel();
}
