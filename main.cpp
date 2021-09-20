#include "PetrolCar.hpp"
#include "ElectricCar.hpp"
#include "HybridCar.hpp"
#include <iostream>

int main()
{

   
   
std::unique_ptr<PetrolCar>Ptr = std::make_unique<PetrolCar>(std::make_unique<PetrolEngine>(120, 1800, 6));
std::unique_ptr<ElectricCar>Ptr2 = std::make_unique<ElectricCar>(std::make_unique<ElectricEngine>(12, 180));

std::unique_ptr<Car>carPtr=std::move(Ptr);
std::unique_ptr<Car>carPtr2=std::move(Ptr2);
carPtr->brake();
carPtr2->brake();
    
    /*
    std::cout << std::endl << "OPEL" << std::endl;
    PetrolCar opel(std::make_shared<PetrolEngine>(120, 1800, 6));
    opel.accelerate(50);
    opel.brake();
    opel.accelerate(-900);
    opel.refuel();

    std::cout << std::endl << "NISSAN" << std::endl;
    ElectricCar nissan(std::make_shared<ElectricEngine>(130,650));
    nissan.charge();
    nissan.getEngine()->setPower(45);
    std::cout<<"nissan engine power "<<nissan.getEngine()->getPower()<<std::endl;
    //nissan.accelerate(80);
    nissan.getEngine() = std::make_shared<ElectricEngine>(150, 700);  // Changing an engine during driving is not safe
    nissan.turnLeft();

    std::cout << std::endl << "TOYOTA" << std::endl;
    HybridCar toyota(std::make_shared<PetrolEngine>(80, 1400, 5), std::make_shared<ElectricEngine>(100, 540));
    toyota.accelerate(100);
    toyota.brake();
    toyota.charge();
    toyota.refuel();
    */
}
