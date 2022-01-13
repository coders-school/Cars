#include "ElectricEngine.hpp"
#include "Car.hpp"

class ElectricCar : public Car
{
public:
    ElectricCar(ElectricEngine* engine);

    ElectricCar(ElectricCar const & car);
    ElectricCar(ElectricCar && car);

    ElectricCar & operator=(ElectricCar const & car);
    ElectricCar & operator=(ElectricCar && car);

    ~ElectricCar() override;
    
    void setEngine(ElectricEngine * engine) ;
    void charge();
    
    friend std::ostream & operator<<(std::ostream & out, ElectricCar const & car);

private:
    ElectricEngine* engine_;
};

