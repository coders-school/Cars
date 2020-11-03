#include "ElectricCar.hpp"
#include "HybridCar.hpp"
#include "PetrolCar.hpp"
#include <iostream>
#include <memory>

int main() {
  std::cout << std::endl << "OPEL" << std::endl;

  std::unique_ptr<ICar> car_ptr;

  PetrolCar opel(
      std::make_unique<PetrolEngine>(Power{120}, Capacity{1800}, Gears{6}));
  car_ptr.reset(&opel);
  car_ptr->fill();
  car_ptr->accelerate(Speed{50});
  car_ptr->brake();
  car_ptr.release();

  std::cout << std::endl << "NISSAN" << std::endl;
  ElectricCar nissan(
      std::make_unique<ElectricEngine>(Power{130}, BatteryCapacity{650}));
  car_ptr.reset(&nissan);
  car_ptr->fill();
  car_ptr->accelerate(Speed{80});
  //  nissan.engine_ = new ElectricEngine(Power{150}, BatteryCapacity{700});  //
  //  Changing an engine during driving is not safe
  car_ptr->turnLeft();
  car_ptr.release();

  std::cout << std::endl << "TOYOTA" << std::endl;
  HybridCar toyota(
      std::make_unique<PetrolEngine>(Power{80}, Capacity{1400}, Gears{5}),
      std::make_unique<ElectricEngine>(Power{100}, BatteryCapacity{540}));
  car_ptr.reset(&toyota);
  car_ptr->accelerate(Speed{100});
  car_ptr->brake();
  car_ptr->fill();
  car_ptr.release();
}
