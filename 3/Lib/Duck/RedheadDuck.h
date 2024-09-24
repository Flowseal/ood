#ifndef REDHEADDUCK_H
#define REDHEADDUCK_H

#include "Dance/DanceMinuet.h"
#include "Duck.h"
#include "Fly/FlyWithWings.h"
#include "Quack/QuackBehavior.h"

#include <memory>

class RedheadDuck : public Duck
{
public:
	RedheadDuck()
		: Duck(CreateFlyWithWings(), CreateQuack(), CreateDanceMinuet())
	{
	}

	void Display() const override
	{
		std::cout << "I'm redhead duck" << std::endl;
	}
};

#endif
