#include "PetrolCar.hpp"
#include "ElectricCar.hpp"
#include "HybridCar.hpp"
#include "Car.hpp"

int main()
{
    Car* car;
    PetrolCar opel(new PetrolEngine(120, 1800, 6));
    car = &opel;
    car->accelerate(50);
    car->brake();
    car->topUp();

    ElectricCar nissan(new ElectricEngine(130, 650));
    car = &nissan;
    car->topUp();
    car->accelerate(80);
    car->turnLeft();

    HybridCar toyota(new PetrolEngine(80, 1400, 5), new ElectricEngine(100, 540));
    car = dynamic_cast<ElectricCar*>(&toyota);
    car->accelerate(100);
    car->brake();
    car->topUp();
}
