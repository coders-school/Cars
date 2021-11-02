#include "PetrolEngine.hpp"
#include "Car.hpp"

class PetrolCar : public Car
{
public:
    PetrolCar(PetrolEngine* engine);
    ~PetrolCar() override;

    void setEngine(PetrolEngine * engine);

private:
    PetrolEngine* engine_;
};

