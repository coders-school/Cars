#include <iostream>
#include "ElectricCar.hpp"
#include "HybridCar.hpp"
#include "Invalidgear.hpp"
#include "PetrolCar.hpp"

int main() {
    std::unique_ptr<PetrolCar> Ptr = std::make_unique<PetrolCar>(std::make_unique<PetrolEngine>(-120, 1800, 6));
    std::unique_ptr<ElectricCar> Ptr2 = std::make_unique<ElectricCar>(std::make_unique<ElectricEngine>(12, 180));
    Ptr->getPetrolEngine()->setCurrentGear(3);
    PetrolCar Car(std::make_unique<PetrolEngine>(-120, 1800, 6));
    
    /*
int p = Ptr2->getElectricEngine()->getPower();
*/
    //std::unique_ptr<Car>carPtr=std::move(Ptr);
    //std::unique_ptr<Car>carPtr2=std::move(Ptr2);

    ///carPtr2->powerSuply();
    //carPtr->changeEngine(4,5,6,7,8);

    try {
        Ptr->getPetrolEngine()->changeGear(4);

    } catch (InvalidGear const& m) {
        std::cout << m.what();
    }

return 0;
}