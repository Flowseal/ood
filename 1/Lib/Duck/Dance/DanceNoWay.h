#ifndef DANCENOWAY_H
#define DANCENOWAY_H

#include "IDanceBehavior.h"
#include <iostream>

class DanceNoWay : public IDanceBehavior
{
public:
	void Dance() override {}
};

#endif
