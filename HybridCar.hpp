#include "ElectricEngine.hpp"
#include "PetrolEngine.hpp"
#include "ElectricCar.hpp"
#include "PetrolCar.hpp"

class HybridCar : public ElectricCar, public PetrolCar
{
public:
    HybridCar(PetrolEngine *petrolEng, ElectricEngine *electricEng);
    ~HybridCar();

    void addEnergy();
    /*zamiast dziedziczenia wirtualnego
    using importuje do danej klasy nazwę
    using PetrolCar::accelerate;
    using PetrolCar::brake;

    lub

    void accelerate(int value){
        PetrolCar::accelerate(value);
    }

    void brake(){

    }

    */

 //   PetrolEngine *petrolEngine_;
 //   ElectricEngine *electricEngine_;
};
