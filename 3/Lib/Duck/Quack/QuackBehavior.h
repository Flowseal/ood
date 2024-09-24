#ifndef QUACKBEHAVIOR_H
#define QUACKBEHAVIOR_H

#include "IQuakBehavior.h"
#include <iostream>

auto CreateQuack = []() {
	return []() {
		std::cout << "Quack quack" << std::endl;
	};
};

#endif
