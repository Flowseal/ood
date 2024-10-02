#include "pch.h"
#include "../2/Observer.h"

#include <iostream>

class TestObserver : public IObserver<int>
{
public:
	bool IsObserving() const
	{
		return m_subject != nullptr;
	}

private:
	void Update(int const& data) override
	{
		std::cout << "Data: " << data << std::endl;
		m_subject->RemoveObserver(*this);
	}
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

TEST(TestObserver, RemoveDuringNotify) {
	TestObservable observable;

	TestObserver observer1;
	TestObserver observer2;

	observable.RegisterObserver(observer1);
	observable.RegisterObserver(observer2);

	EXPECT_NO_THROW(observable.DataChanged());
	EXPECT_FALSE(observer1.IsObserving());
	EXPECT_FALSE(observer1.IsObserving());
}