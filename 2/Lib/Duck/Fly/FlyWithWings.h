#ifndef FLYWITHWINGS_H
#define FLYWITHWINGS_H

#include "IFlyBehavior.h"
#include <iostream>

class FlyWithWings : public IFlyBehavior
{
public:
	void Fly() override
	{
		m_flighCount++;
		std::cout << "I'm flying with wings!! Fligh number " << m_flighCount << std::endl;
	}

	int GetFlighCount() override
	{
		return m_flighCount;
	}

private:
	int m_flighCount = 0;
};

#endif
