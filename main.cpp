#include <iostream>
#include "ElectricCar.hpp"
#include "HybridCar.hpp"
#include "Invalidgear.hpp"
#include "PetrolCar.hpp"

int main() {
    //std::unique_ptr<ElectricCar> Ptr2 = std::make_unique<ElectricCar>(std::make_unique<ElectricEngine>(12, 180));

    //PetrolCar Audi(std::make_unique<PetrolEngine>(0, 4, 5));

    ElectricCar Aud(std::make_unique<ElectricEngine>(12, 180));
    
    /*

    PetrolCar toyota(std::make_unique<PetrolEngine>(3, 1, 5));
    toyota.getPetrolEngine()->setCurrentGear(3);
    toyota.getPetrolEngine()->changeGear(1);

    PetrolCar t(std::make_unique<PetrolEngine>(2, 3, 4));
    t.getPetrolEngine()->setCurrentGear(3);
    t.getPetrolEngine()->changeGear(1);
*/
    return 0;
}