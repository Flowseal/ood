#include "../Lib/Duck/Fly/FlyNoWay.h"
#include "../Lib/Duck/MallardDuck.h"
#include "../Lib/Duck/Quack/MuteQuackBehavior.h"
#include "pch.h"

TEST(DuckTest, QuackAfterFlyTest)
{
	int quackCount = 0;
	auto mockQuack = [&quackCount]() {
		quackCount++;
	};

	MallardDuck duck;
	duck.SetQuackBehavior(mockQuack);

	/* Quack should be called 4 times:
			1 time for called Quack function
			2 times for default fly strategy
			1 time for new fly strategy
	*/

	duck.Quack(); // 1st Quack
	EXPECT_EQ(quackCount, 1);

	duck.Fly();
	duck.Fly(); // 2nd Quack
	EXPECT_EQ(quackCount, 2);

	duck.Fly();
	duck.Fly(); // 3rd Quack
	EXPECT_EQ(quackCount, 3);

	duck.Fly();
	EXPECT_EQ(quackCount, 3);

	// New fly strategy - count should reset to 0
	duck.SetFlyBehavior(CreateFlyWithWings());
	duck.Fly();
	duck.Fly(); // 4th quack
	EXPECT_EQ(quackCount, 4);

	duck.Fly();

	// New fly strategy - we can't fly so no Quack
	duck.SetFlyBehavior(CreateFlyNoWay());
	duck.Fly();
	duck.Fly(); // No quack should be called

	EXPECT_EQ(quackCount, 4);
}