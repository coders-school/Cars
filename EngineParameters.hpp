#pragma once

struct Speed {
  explicit Speed(unsigned int speed) : speed_(speed) {}
  unsigned int speed_;
};

struct BatteryCapacity {
  int batteryCapacity_ = 0; // unsigned int ? in Ah
};

struct Power {
  int power_ = 0; // in HP
};

struct Capacity {
  float capacity_ = 0.0; // in ccm
};

struct Gears {
  int gears_; // enum?
};
