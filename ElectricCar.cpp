#include "ElectricCar.hpp"
#include <iostream>
#include "InvalidEngine.hpp"
#include "MovingCar.hpp"

//ElectricCar::ElectricCar(ElectricEngine* engine)
 ElectricCar::ElectricCar(std::shared_ptr<ElectricEngine> engine)
    : engine_(engine) {
    std::cout << __FUNCTION__ << std::endl;
}

ElectricCar::~ElectricCar() {
    //delete engine_;
    std::cout << __FUNCTION__ << std::endl;
}
void ElectricCar::charge() {
    std::cout << __FUNCTION__ << std::endl;
}
void ElectricCar::restore() {
    charge();
}

//void ElectricCar::changeEngine(Engine* engine) {
void ElectricCar::changeEngine(std::shared_ptr<ElectricEngine> engine){ 
    std::cout << __FUNCTION__ << std::endl;
    if (getSpeed() != 0) {
        throw MovingCar("Car is in move");
    } else {
        engine_ = engine;
    }   
}
