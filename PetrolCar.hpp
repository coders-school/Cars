#include "PetrolEngine.hpp"
#include "Car.hpp"
#include <iostream>

class PetrolCar : public Car
{
public:
    PetrolCar(PetrolEngine* engine);

    PetrolCar(const PetrolCar &);
    PetrolCar(PetrolCar &&);

    PetrolCar & operator=(const PetrolCar &);
    PetrolCar & operator=(PetrolCar &&);

    ~PetrolCar() override;

    void setEngine(PetrolEngine * engine);
    //const PetrolEngine* getPetrolEngine() const;
    PetrolEngine & getPetrolEngine();

    friend std::ostream & operator<<(std::ostream & out, PetrolCar const & car);

private:
    PetrolEngine* engine_;
};

