#pragma once
#include <map>

class PetrolEngine {
public:
    PetrolEngine(int power, float capacity, int gears, int maxFuelTank);
    void changeGear(int gear);

    int power_;       // in HP
    float capacity_;  // in ccm
    int gears_;
    int currentGear_;
    int maxFuelTank_;      //in l
    int currentFuelTank_;  //in l
    std::map<int, std::string> gearBoxMap_ {{-1, "rear"},
                                           {0, "neutral"},
                                           {1, "first"},
                                           {2, "second"},
                                           {3, "third"},
                                           {4, "fourth"},
                                           {5, "fifth"},
                                           {6, "sixth"}};
};
