#pragma once

class PetrolEngine
{
  public:
    PetrolEngine(int power, float capacity, int gears);
    void changeGear(int gear) noexcept(false);
    int power() const;
    int capacity() const;

  private:
    void throwOnUnallowedGearChange(int gear) const noexcept(false);
    int power_;   // in HP
    float capacity_;   // in ccm
    int gears_;
    int currentGear_;
};
