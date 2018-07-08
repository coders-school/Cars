#include "ElectricEngine.hpp"
#include "PetrolEngine.hpp"
#include "ElectricCar.hpp"
#include "PetrolCar.hpp"

class HybridCar : virtual public PetrolCar, virtual public ElectricCar
{
public:
    HybridCar(PetrolEngine* petrolEng, ElectricEngine* electricEng)
        : PetrolCar(petrolEng)
        , ElectricCar(electricEng)
    {}
    ~HybridCar() {}
    void accelerate(int speed) {
        PetrolCar::accelerate(speed);
    }
    void refill() {}
};

