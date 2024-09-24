#ifndef MODELDUCK_H
#define MODELDUCK_H

#include "Dance/DanceNoWay.h"
#include "Duck.h"
#include "Fly/FlyNoWay.h"
#include "Quack/MuteQuackBehavior.h"

class ModelDuck : public Duck
{
public:
	ModelDuck()
		: Duck(CreateFlyNoWay(), CreateMuteQuack(), CreateDanceNoWay())
	{
	}

	void Display() const override
	{
		std::cout << "I'm model duck" << std::endl;
	}
};

#endif
