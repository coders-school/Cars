#include <iostream>
#include "ElectricCar.hpp"
#include "HybridCar.hpp"
#include "PetrolCar.hpp"

int main() {
    PetrolEngine defaultEngine = PetrolEngine(HorsePower(100), CubicCentimetre(1500), Gear(5));
    Vehicle* veh = new PetrolCar(new PetrolEngine{defaultEngine}, Litre(60));
    veh->turnLeft();
    
    std::cout << std::endl
              << "OPEL" << std::endl;
    PetrolCar opel(new PetrolEngine{defaultEngine}, Litre(50));
    delete veh;
    veh = &opel;
    veh->changeSpeedTo(KMH(100));
    veh->restore();
}
