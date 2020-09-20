#include "ElectricEngine.hpp"
#include <iostream>

ElectricEngine::ElectricEngine(int power, int batteryCapacity) : power_(power), batteryCapacity_(batteryCapacity) {
    std::cout << __FUNCTION__ << std::endl;
}

void ElectricEngine::getInfoEngine() {
    std::cout << "Electric Engine: \n";
    std::cout << "Power = " << power_ << "\n";
    std::cout << "Battery capacity = " << batteryCapacity_ << "\n";
}