#include "ElectricEngine.hpp"
#include <iostream>

ElectricEngine::ElectricEngine(HorsePower power, AmpereHour batteryCapacity) : power_(power), batteryCapacity_(batteryCapacity) {
    std::cout << __FUNCTION__ << std::endl;
}

ElectricEngine::~ElectricEngine() {
        std::cout << __FUNCTION__ << std::endl;

}
