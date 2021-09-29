#include "tools/catch.hpp"
#include "PetrolEngine.hpp"

const int maxNumberOfGears = 20;

struct PetrolEngineMockup : public PetrolEngine {
	PetrolEngineMockup(int numberOfGears):
		PetrolEngine(0, 0, numberOfGears)
	{}
};

TEST_CASE("PetrolEngine changeGear operation", "[void changeGear(int gear)]") {
	WHEN("setting the gear to -2") {
		PetrolEngineMockup petrolEngine(6);
		THEN("changeGear should throw an exception") {
			REQUIRE_THROWS(petrolEngine.changeGear(-2));
		}
	}
	WHEN("setting to high gear") {
		THEN("changeGear should throw an exception") {
			for (size_t numberOfGears = 0; numberOfGears < maxNumberOfGears; ++numberOfGears) {
				PetrolEngineMockup petrolEngine(numberOfGears);
				for (size_t gear = -1; gear <= numberOfGears; ++gear) {
					petrolEngine.changeGear(gear);
				}
				REQUIRE_THROWS(petrolEngine.changeGear(numberOfGears + 1));
			}
		}
	}
	WHEN("changing gears to fast") {
		THEN("changeGear should throw an exception") {
			for (size_t numberOfGears = 0; numberOfGears < maxNumberOfGears; ++numberOfGears) {
				PetrolEngineMockup petrolEngine(numberOfGears);
				REQUIRE_THROWS(petrolEngine.changeGear(maxNumberOfGears));
			}
		}
	}
	WHEN("setting the gear to -1 or 0") {
		THEN("changeGear should never throw an exception") {
			for (size_t numberOfGears = 0; numberOfGears < maxNumberOfGears; ++numberOfGears) {
				PetrolEngineMockup petrolEngine(numberOfGears);
				REQUIRE_NOTHROW(petrolEngine.changeGear(-1));
				REQUIRE_NOTHROW(petrolEngine.changeGear(0));
			}
		}
	}
	WHEN("setting the gears in order") {
		THEN("changeGear should never throw an exception") {
			for (size_t numberOfGears = 0; numberOfGears < maxNumberOfGears; ++numberOfGears) {
				PetrolEngineMockup petrolEngine(numberOfGears);
				for (size_t gear = -1; gear <= numberOfGears; ++gear) {
					REQUIRE_NOTHROW(petrolEngine.changeGear(gear));
				}
			}
		}
	}	
}
