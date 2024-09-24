#ifndef DANCEWALTZ_H
#define DANCEWALTZ_H

#include "IDanceBehavior.h"
#include <iostream>

auto CreateDanceWaltz = []() {
	return []() {
		std::cout << "I'm dancing waltz!!" << std::endl;
	};
};

#endif
