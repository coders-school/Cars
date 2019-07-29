#ifndef ELECTRICCAR_H
#define ELECTRICCAR_H

#include "ElectricEngine.hpp"
#include "Car.hpp"

class ElectricCar : virtual public Car
{
    ElectricEngine* engine_;

public:
    // Constructor
    ElectricCar(ElectricEngine* engine);
    
    // Destrctor
    ~ElectricCar();
    
    void fill() override;


    ElectricEngine getElectricEngine() const;
};

#endif // !ELECTRICCAR_H