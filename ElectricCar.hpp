#include "ElectricEngine.hpp"
#include "Car.hpp"

class ElectricCar : public Car
{
public:
    ElectricCar(ElectricEngine* engine);
    ~ElectricCar() override;
    
    void setEngine(ElectricEngine * engine) ;
    void charge();

private:
    ElectricEngine* engine_;
};

