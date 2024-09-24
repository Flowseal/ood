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
		: Duck(std::make_unique<FlyNoWay>(), std::make_unique<MuteQuackBehavior>(), std::make_unique<DanceNoWay>())
	{
	}

	void Display() const override
	{
		std::cout << "I'm model duck" << std::endl;
	}
};

#endif
