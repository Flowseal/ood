#include "pch.h"
#include "../Lib/Duck/MallardDuck.h"

class MockDanceBehavior : public IDanceBehavior
{
public:
	MOCK_METHOD(void, Dance, (), (override));
};

TEST(DuckTest, DanceTest)
{
	auto mockDanceBehavior = std::make_unique<MockDanceBehavior>();
	EXPECT_CALL(*mockDanceBehavior.get(), Dance()).Times(1);

	MallardDuck duck;
	duck.SetDanceBehavior(std::move(mockDanceBehavior));

	duck.Dance();
}