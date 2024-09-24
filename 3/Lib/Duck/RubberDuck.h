#ifndef RUBBERDUCK_H
#define RUBBERDUCK_H

#include "Dance/DanceNoWay.h"
#include "Duck.h"
#include "Fly/FlyNoWay.h"
#include "Quack/SqueakBehavior.h"
#include <iostream>

class RubberDuck : public Duck
{
public:
	RubberDuck()
		: Duck(CreateFlyNoWay(), CreateSqueak(), CreateDanceNoWay())
	{
	}

	void Display() const override
	{
		std::cout << "I'm rubber duck" << std::endl;
	}
};

#endif
