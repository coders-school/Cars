#include <vector>
#include "InvalidGear.hpp"
#include "PetrolCar.hpp"
#include "gtest/gtest.h"

TEST(ExceptionTest, ThrowsInvalidGearException) {
    int maxGears = 6;
    PetrolCar opel(std::make_unique<PetrolEngine>(120, 1800, maxGears));
    auto testedGears = std::vector<int>{-2, maxGears + 1};
    for (size_t i = 0; i < testedGears.size(); i++) {
        EXPECT_THROW({
            try {
                opel.changeGear(testedGears[i]);
                FAIL() << "ERROR: function changeGear() should throw an error\n";
            } catch (const InvalidGear& exception) {
                EXPECT_STREQ(exception.what(), "Invalid gear");
                throw;
            } catch (const std::logic_error& exception) {
                FAIL() << "ERROR: Was expecting InvalidGear exception: " << exception.what() << std::endl;
            } catch (...) {
                FAIL() << "ERROR: Unexpected exception thrown: " << std::current_exception << std::endl;
            }
        },
                     InvalidGear);
    }
}
