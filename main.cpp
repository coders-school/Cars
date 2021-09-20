#include <iostream>
#include "ElectricCar.hpp"
#include "HybridCar.hpp"
#include "PetrolCar.hpp"

#include "PetrolEngine.hpp"
#include "ElectricEngine.hpp"

int main() {
    std::cout << std::endl
              << "OPEL" << std::endl;
    PetrolCar opel(std::make_unique<PetrolEngine>(120, 1800, 6));
    opel.accelerate(50);
    opel.brake();
    opel.accelerate(-900);
    opel.refuel();

    opel.changeGear(3);
    //opel.changeGear(-1);

    std::cout << std::endl
              << "NISSAN" << std::endl;
    ElectricCar nissan(std::make_unique<ElectricEngine>(130, 650));
    nissan.charge();
    nissan.accelerate(80);
    //nissan.engine_ = std::make_unique<ElectricEngine>(150, 700);  // Changing an engine during driving is not safe
    nissan.turnLeft();

    std::cout << std::endl
              << "TOYOTA" << std::endl;
    HybridCar toyota(std::make_unique<PetrolEngine>(80, 1400, 5),
                     std::make_unique<ElectricEngine>(100, 540));
    toyota.accelerate(100);
    toyota.brake();
    toyota.charge();
    toyota.refuel();

    try{
        toyota.changeGear(3);
        toyota.changeGear(-1);
    } catch (const std::logic_error& err) {
        std::cout << err.what() <<'\n';
    }
    
}
