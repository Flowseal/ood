#ifndef SQUEAKBEHAVIOR_H
#define SQUEAKBEHAVIOR_H

#include "IQuakBehavior.h"
#include <iostream>

auto CreateSqueak = []() {
	return []() {
		std::cout << "Squeak!!!" << std::endl;
	};
};

#endif
