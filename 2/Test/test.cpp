#include "pch.h"
#include "../Lib/Duck/MallardDuck.h"
#include "../Lib/Duck/Fly/FlyNoWay.h"
#include "../Lib/Duck/Quack/MuteQuackBehavior.h"

class MockQuackBehavior : public IQuackBehavior
{
public:
	MOCK_METHOD(void, Quack, (), (override));
};

TEST(DuckTest, QuackAfterFlyTest)
{
	auto mockQuackBehavior = std::make_unique<MockQuackBehavior>();
	EXPECT_CALL(*mockQuackBehavior.get(), Quack()).Times(4);

	MallardDuck duck;
	duck.SetQuackBehavior(std::move(mockQuackBehavior));

	/* Quack should be called 4 times:
			1 time for called Quack function
			2 times for default fly strategy
			1 time for new fly strategy
	*/

	duck.Quack(); // 1st Quack
	duck.Fly();
	duck.Fly(); // 2nd Quack
	duck.Fly();
	duck.Fly(); // 3rd Quack
	duck.Fly();

	// New fly strategy - count should reset to 0
	duck.SetFlyBehavior(std::make_unique<FlyWithWings>());
	duck.Fly();
	duck.Fly(); // 4th quack
	duck.Fly();

	// New fly strategy - we can't fly so no Quack
	duck.SetFlyBehavior(std::make_unique<FlyNoWay>());
	duck.Fly();
	duck.Fly(); // No quack should be called

}