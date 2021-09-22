#include "Car.hpp"
#include "ElectricCar.hpp"
#include "ElectricEngine.hpp"
#include "Engine.hpp"
#include "HybridCar.hpp"
#include "PetrolCar.hpp"
#include "PetrolEngine.hpp"

#include <iostream>

int main()
{
    Car* car;
    Engine* electricEngine;
    Engine* petrolEngine;
    PetrolEngine petrolEng (80, 1400, 20);
    petrolEngine = &petrolEng;

    std::cout << std::endl << "OPEL" << std::endl;
    PetrolCar opel(petrolEngine);
    car = &opel;
    car->accelerate(50);
    car->brake();
    car->accelerate(-900);
    car->fillUp();
    try {
        opel.changeGear(1, petrolEng);
    } catch (const PetrolEngine::InvalidGear & error){
        std::cout << error.what() << '\n';
    }

    std::cout << std::endl << "NISSAN" << std::endl;
    ElectricEngine electricEng(100, 1110);
    electricEngine = &electricEng;
    ElectricCar nissan(electricEngine);
    car = &nissan;
    car->fillUp();
    car->accelerate(80);
    ElectricEngine newElectricEngine(150, 700);
    car->turnLeft();

    std::cout << std::endl << "TOYOTA" << std::endl;
    HybridCar toyota(electricEngine, petrolEngine);
    car->accelerate(100);
    car->brake();
    car->fillUp();
}
