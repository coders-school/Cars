#include "ICar.hpp"
#include "PetrolEngine.hpp"
#include <memory>

class PetrolCar : public ICar {
public:
  PetrolCar(std::unique_ptr<IEngine> engine);
  ~PetrolCar();

  void start_engine() const override;
  void stop_engine() const override;
  void fill() override;
  void refuel();

private:
  std::unique_ptr<IEngine> engine_ = nullptr;
};
