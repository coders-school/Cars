#include <iostream>

#include "car/Car.hpp"
#include "car/PetrolCar.hpp"
#include "car/ElectricCar.hpp"
#include "car/HybridCar.hpp"
#include "engine/Engine.hpp"
#include "engine/PetrolEngine.hpp"
#include "engine/ElectricEngine.hpp"

int main()
{
    Car* car;

    car = new PetrolCar(new PetrolEngine(120, 1800, 6));
    car->accelerate(90);
    car->turnLeft();
    car->turnRight();
    car->brake();
    car->restore();
    delete car;
    std::cout << "-----------------------" << std::endl;

    car = new ElectricCar(new ElectricEngine(130, 650));
    car->accelerate(90);
    car->turnLeft();
    car->turnRight();
    car->brake();
    car->restore();
    delete car;
    std::cout << "-----------------------" << std::endl;

    car = new HybridCar(new PetrolEngine(90, 1400, 4),
                        new ElectricEngine(80, 420));
    car->accelerate(90);
    car->turnLeft();
    car->turnRight();
    car->brake();
    car->restore();
    delete car;
    std::cout << "-----------------------" << std::endl;
    

    // car = new ElectricCar(engine);
    // std::cout << std::endl << "OPEL" << std::endl;
    // PetrolCar opel(new PetrolEngine(120, 1800, 6));
    // opel.accelerate(50);
    // opel.brake();
    // opel.accelerate(-900);
    // opel.refuel();

    // std::cout << std::endl << "NISSAN" << std::endl;
    // ElectricCar nissan(new ElectricEngine(130, 650));
    // nissan.charge();
    // nissan.accelerate(80);
    // nissan.engine_ = new ElectricEngine(150, 700);  // Changing an engine during driving is not safe
    // nissan.turnLeft();

    // std::cout << std::endl << "TOYOTA" << std::endl;
    // HybridCar toyota(new PetrolEngine(80, 1400, 5), new ElectricEngine(100, 540));
    // toyota.accelerate(100);
    // toyota.brake();
    // toyota.charge();
    // toyota.refuel();
}
