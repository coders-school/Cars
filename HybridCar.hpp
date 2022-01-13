#include "ElectricEngine.hpp"
#include "PetrolEngine.hpp"
#include "Car.hpp"

class HybridCar : public Car
{
public:
    HybridCar(PetrolEngine* petrolEng, ElectricEngine* electricEng);

    HybridCar(HybridCar const & car);
    HybridCar(HybridCar && car);

    HybridCar & operator=(HybridCar const & car);
    HybridCar & operator=(HybridCar && car);

    ~HybridCar() override;
    
    void setEngine(PetrolEngine* petrolEngine, ElectricEngine * electricEngine);
    void charge();
    void refuel();

    friend std::ostream & operator<<(std::ostream & out, HybridCar const & car);
    
private:
    PetrolEngine* petrolEngine_;
    ElectricEngine* electricEngine_;
};

