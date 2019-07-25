#include "ElectricEngine.hpp"
#include "PetrolEngine.hpp"
#include "ElectricCar.hpp"
#include "PetrolCar.hpp"

class HybridCar : public ElectricCar
{
private:
    PetrolEngine* engine_;
public:
    HybridCar(Engine*, PetrolEngine*);
    ~HybridCar();
    void feed() override;
    void changeEngine(Engine* engine) override;
};

