#ifndef DANCEMINUET_H
#define DANCEMINUET_H

#include "IDanceBehavior.h"
#include <iostream>

auto CreateDanceMinuet = []() {
	return []() {
		std::cout << "I'm dancing minuet!!" << std::endl;
	};
};

#endif
