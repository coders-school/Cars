#pragma once

enum class ManualGear : int {
   reverse = -1,
   neutral,
   g_1st,
   g_2nd,
   g_3th, 
   g_4th,
   g_5th, 
   g_6th,
   g_7th,
   g_8th,
   g_9th,
   Limit = g_9th
};

class Gearable {
public:
   virtual ~Gearable() = default;
   virtual void changeGear(int gear) = 0;
};