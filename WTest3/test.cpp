#include "pch.h"
#include "../3/Observer.h"

#include <ostream>
#include <sstream>

class TestObserver1 : public IObserver<int>
{
public:
	TestObserver1(std::ostream& stream)
		: output(stream)
	{
	}

private:
	void Update(int const& data) override
	{
		output << "1";
	}

	std::ostream& output;
};

class TestObserver2 : public IObserver<int>
{
public:
	TestObserver2(std::ostream& stream)
		: output(stream)
	{
	}

private:
	void Update(int const& data) override
	{
		output << "2";
	}

	std::ostream& output;
};

class TestObservable : public CObservable<int>
{
public:
	void DataChanged()
	{
		NotifyObservers();
	}

protected:
	int GetChangedData() const override
	{
		return 1234;
	}
};

TEST(TestObserver, PriorityTest)
{
	TestObservable observable{};

	std::stringstream ss;
	TestObserver1 observer1(ss);
	TestObserver2 observer2(ss);

	observable.RegisterObserver(observer1, 100);
	observable.RegisterObserver(observer2, 1);
	observable.RegisterObserver(observer2, 1);

	observable.DataChanged();
	observable.RemoveObserver(observer2);

	observable.DataChanged();
	observable.RegisterObserver(observer2, 200);

	observable.DataChanged();
	EXPECT_EQ(ss.str(), "12121");
}