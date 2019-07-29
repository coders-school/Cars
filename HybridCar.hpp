#ifndef HYBRIDCAR_H
#define HYBRIDCAR_H

#include "ElectricCar.hpp"
#include "PetrolCar.hpp"

class HybridCar : public PetrolCar, public ElectricCar
{
public:
    HybridCar(PetrolEngine* petrolEng, ElectricEngine* electricEng);
    ~HybridCar();

    void fill() override;
};



#endif // !HYBRIDCAR_H