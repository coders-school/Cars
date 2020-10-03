#pragma once

#include <sstream>
#include <stdexcept>

class InvalidGear : public std::logic_error {
public:
  InvalidGear(std::string p_msg);
  const char *what() const throw() override;
};
