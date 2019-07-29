#ifndef PETROLCAR_H
#define PETROLCAR_H

#include "PetrolEngine.hpp"
#include "Car.hpp"


class PetrolCar : virtual public Car
{
    PetrolEngine* engine_;
public:
    PetrolCar(PetrolEngine* engine);
    ~PetrolCar();

    void fill() override;

    PetrolEngine GetPetrolEngine() const;

    void ChangePetrolEngine(PetrolEngine* engine);
};

#endif // !PETROLCAR_H 