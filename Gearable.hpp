#pragma once

class Gearable {
public:
   virtual ~Gearable() = default;
   virtual void changeGear(int gear) = 0;
};