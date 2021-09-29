#include <iostream>
#include "ElectricCar.hpp"
#include "HybridCar.hpp"
#include "Invalidgear.hpp"
#include "PetrolCar.hpp"

int main() {
    std::unique_ptr<ElectricCar> Ptr = std::make_unique<ElectricCar>(std::make_unique<ElectricEngine>(12, 180));

    PetrolCar toyota(std::make_unique<PetrolEngine>(3, 1, 5));
    toyota.getPetrolEngine()->setCurrentGear(3);
    toyota.getPetrolEngine()->changeGear(2);

    ElectricCar Audi(std::make_unique<ElectricEngine>(2, 3));
    Audi.getElectricEngine()->setBatteryCapacity(10);
    std::cout<<Audi.getElectricEngine()->getBatteryCapacity()<<std::endl;
    Audi.changeEngine(88,22);
    std::cout<<Audi.getElectricEngine()->getBatteryCapacity()<<std::endl;
    
    return 0;
}