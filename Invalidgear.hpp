#include <stdexcept>

struct InvalidGear : public std::logic_error {
    InvalidGear(std::string const& sentence)
        : std::logic_error(sentence) {}
};