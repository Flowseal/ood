#ifndef FLYWITHWINGS_H
#define FLYWITHWINGS_H

#include "IFlyBehavior.h"
#include <iostream>

auto CreateFlyWithWings = []() {
	int flightCount = 0;
	return [=]() mutable {
		flightCount++;
		std::cout << "I'm flying with wings!! Flight number " << flightCount << std::endl;
		return flightCount;
	};
};

#endif
