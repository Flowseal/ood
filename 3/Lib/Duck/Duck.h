#ifndef DUCK_H
#define DUCK_H

#include "Dance/IDanceBehavior.h"
#include "Fly/IFlyBehavior.h"
#include "Quack/IQuakBehavior.h"

#include <cassert>
#include <iostream>
#include <memory>
#include <vector>

class Duck
{
public:
	Duck(FlyBehavior flyBehavior,
		QuackBehavior quackBehavior,
		DanceBehavior danceBehavior)
		: m_quackBehavior(std::move(quackBehavior))
		, m_flyBehavior(std::move(flyBehavior))
		, m_danceBehavior(std::move(danceBehavior))
	{
		assert(m_quackBehavior);
		assert(m_flyBehavior);
		assert(m_danceBehavior);
	}

	void Quack() const
	{
		m_quackBehavior();
	}

	void Swim()
	{
		std::cout << "I'm swimming" << std::endl;
	}

	void Fly()
	{
		int flighCount = m_flyBehavior();

		if (flighCount > 0 && flighCount % 2 == 0)
		{
			m_quackBehavior();
		}
	}

	void Dance()
	{
		m_danceBehavior();
	}

	void SetFlyBehavior(FlyBehavior flyBehavior)
	{
		assert(flyBehavior);
		m_flyBehavior = std::move(flyBehavior);
	}

	void SetDanceBehavior(DanceBehavior danceBehavior)
	{
		assert(danceBehavior);
		m_danceBehavior = std::move(danceBehavior);
	}

	void SetQuackBehavior(QuackBehavior quackBehavior)
	{
		assert(quackBehavior);
		m_quackBehavior = std::move(quackBehavior);
	}

	virtual void Display() const = 0;
	virtual ~Duck() = default;

private:
	FlyBehavior m_flyBehavior;
	QuackBehavior m_quackBehavior;
	DanceBehavior m_danceBehavior;
};

#endif
