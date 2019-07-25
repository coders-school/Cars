#include "PetrolCar.hpp"
#include "ElectricCar.hpp"
#include "HybridCar.hpp"
#include "Car.hpp"
#include"Exceptions.hpp"
#include <iostream>
#include <assert.h>

void checkPoint(Car* point)
{
    assert(point!=NULL);
    std::cout<<"Pointer is ok"<<std::endl;
}
void checkPoint(Car* point,Car &NewAdress, Car &OldAdress)
{
    point->gettypeCar();
    point = &NewAdress;
    assert(point!=(&OldAdress));
    std::cout<<"Pointer has new adress"<<std::endl;
    point->gettypeCar();
}
int main()
{
    PetrolCar opel(new PetrolEngine(120, 1800, 6));
    ElectricCar nissan(new ElectricEngine(130, 650));
    HybridCar toyota(new PetrolEngine(80, 1400, 5), new ElectricEngine(100, 540));
    Car *  Pointer;

    Pointer = &opel;
    checkPoint(Pointer);
    checkPoint(Pointer,nissan,opel);

    std::cout << std::endl << "OPEL" << std::endl;
    Pointer->getSpeed();
    std::cout<< "Current gear is: " << opel.getCurrentGear() << std::endl;
    opel.setGear(2);
    std::cout<< "Current gear after change is: " << opel.getCurrentGear() << std::endl;
    opel.setGear(-1);
    opel.accelerate(50);
    opel.getSpeed();
    opel.brake();
    opel.changeEngine(150,1000,5);
    opel.accelerate(-900);
    opel.accelerate(500);
    opel.refuel();

    std::cout << std::endl << "NISSAN" << std::endl;

    nissan.charge();
    nissan.accelerate(80);
    nissan.changeEngine(100,100);
    //nissan.engine_ = new ElectricEngine(150, 700);  // Changing an engine during driving is not safe
    nissan.turnLeft();

    std::cout << std::endl << "TOYOTA" << std::endl;
  //  HybridCar toyota(new PetrolEngine(80, 1400, 5), new ElectricEngine(100, 540));
    toyota.accelerate(100);
    toyota.brake();
    toyota.charge();
    toyota.refuel();
    toyota.changeEngine(100,100);
    toyota.changeEngine(100,100,100);

    delete Pointer;
}
