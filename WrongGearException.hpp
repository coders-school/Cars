#include <exception>

class WrongGearException : public std::exception {

public:
void what();

    
};