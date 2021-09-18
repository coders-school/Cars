#include "PetrolCar.hpp"
#include "ElectricCar.hpp"
#include "HybridCar.hpp"
#include <iostream>
#include <memory>


int main()
{
    
    std::cout << std::endl << "OPEL" << std::endl;
    PetrolCar opel(std::make_shared<PetrolEngine>(120, 1800, 6));
    opel.accelerate(50);
    opel.brake();
    opel.accelerate(-900);
    opel.refuel();

    std::cout << std::endl << "NISSAN" << std::endl;
    ElectricCar nissan(std::make_shared<ElectricEngine>(130, 650));
    nissan.charge();
    nissan.accelerate(80);
    //nissan.engine_ = new ElectricEngine(150, 700);  // Changing an engine during driving is not safe
    nissan.turnLeft();

    std::cout << std::endl << "TOYOTA" << std::endl;
    HybridCar toyota(std::make_shared<PetrolEngine>(80, 1400, 5), std::make_shared<ElectricEngine>(100, 540));
    toyota.accelerate(100);
    toyota.brake();
    toyota.charge();
    toyota.refuel();
    
   try { toyota.changeGear(0);
   } 
    catch (InvalidGear& gearerr)
    {
    std::cout << gearerr.what() << "\n";
    };

    try {
    toyota.changeGear(6);
    } 
    catch (InvalidGear& gearerr)
    {
    std::cout << gearerr.what() << "\n";
    };

        try {
    toyota.changeGear(0);
    } 
    catch (InvalidGear& gearerr)
    {
    std::cout << gearerr.what() << "\n";
    };

        try {
    toyota.changeGear(-1);
    } 
    catch (InvalidGear& gearerr)
    {
    std::cout << gearerr.what() << "\n";
    };
    
    
}
