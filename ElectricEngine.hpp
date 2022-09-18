#pragma once

class ElectricEngine
{
  public:
    ElectricEngine(int power, int batteryCapacity);

    int power()const;
    int batteryCapacity() const;

  private:
    int power_;   // in HP
    int batteryCapacity_;   // in Ah
};
