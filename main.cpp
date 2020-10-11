#include <iostream>
#include "Car.hpp"
#include "ElectricCar.hpp"
#include "HybridCar.hpp"
#include "PetrolCar.hpp"

#include "Exception.hpp"

int main() {
    Car* car{};
    std::cout << std::endl << "OPEL" << std::endl;
    PetrolCar opel(std::make_unique<PetrolEngine>(120, 1800, 6));
    car = &opel;
    car->brake();
    car->accelerate(50);
    car->restore();
    try {
        opel.getEngine()->changeGear(2);
        opel.getEngine()->changeGear(-1);
        car->accelerate(900);
    } catch (const InvalidGear& ex) {
        std::cout << ex.what() << '\n'; 
    } catch (const InvalidAcceleration& ex) {
        std::cout << ex.what() << '\n';
    }

    

    opel.changeEngine(std::make_unique<PetrolEngine>(130, 1200, 7));

    std::cout << std::endl << "NISSAN" << std::endl;
    ElectricCar nissan(std::make_unique<ElectricEngine>(130, 650));
    car = &nissan;
    car->restore();
    car->accelerate(80);
    car->turnLeft();
    nissan.changeEngine(std::make_unique<ElectricEngine>(145, 700));  // Changing an engine during driving is not safe

    

    std::cout << std::endl << "TOYOTA" << std::endl;
    HybridCar toyota(std::make_unique<PetrolEngine>(80, 1400, 5), std::make_unique<ElectricEngine>(100, 540));
    car = &toyota;
    car->accelerate(100);
    car->brake();
    car->restore();
    
    
    toyota.changeEngine(std::make_unique<ElectricEngine>(145, 700));
    toyota.changeEngine(std::make_unique<PetrolEngine>(130, 1200, 7));

    
}
