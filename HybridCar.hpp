#include "ElectricEngine.hpp"
#include "PetrolEngine.hpp"
#include "Car.hpp"

class HybridCar : public Car
{
public:
    HybridCar(PetrolEngine* petrolEng, ElectricEngine* electricEng);
    ~HybridCar() override;
    
    void setEngine(PetrolEngine* petrolEngine, ElectricEngine * electricEngine);
    void charge();
    void refuel();
private:
    PetrolEngine* petrolEngine_;
    ElectricEngine* electricEngine_;
};

