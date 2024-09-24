#ifndef MALLARDDUCK_H
#define MALLARDDUCK_H

#include "Dance/DanceWaltz.h"
#include "Duck.h"
#include "Fly/FlyWithWings.h"
#include "Quack/QuackBehavior.h"

class MallardDuck : public Duck
{
public:
	MallardDuck()
		: Duck(CreateFlyWithWings(), CreateQuack(), CreateDanceWaltz())
	{
	}

	void Display() const override
	{
		std::cout << "I'm mallard duck" << std::endl;
	}
};

#endif
