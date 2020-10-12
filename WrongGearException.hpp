#include <stdexcept>
#include <string>

class WrongGearException : public std::logic_error {

public:
  using std::logic_error::logic_error;
  WrongGearException(int gear, int gears_);
};
