#include <exception>
#include <string>
class WrongGearException : public std::exception {

public:
  WrongGearException(int gear, int gears_);
  const char *what() const noexcept;

private:
  int gears_;
  int gear_;
  std::string msg;
};
