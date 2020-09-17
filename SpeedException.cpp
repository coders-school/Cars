#include "SpeedException.hpp"

const char * SpeedException::what() const noexcept {
    return msg_.c_str();
}