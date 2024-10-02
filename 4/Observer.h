#pragma once

#include <map>
#include <unordered_map>
#include <unordered_set>

template <typename T>
class IObservable;

template <typename T>
class CObservable;


template <typename T>
class IObserver
{
public:
	virtual ~IObserver() = default;

protected:
	virtual void Update(T const& data, const CObservable<T>* observable) = 0;
	IObservable<T>* m_subject;

	friend class CObservable<T>;
};


template <typename T>
class IObservable
{
public:
	virtual ~IObservable() = default;
	virtual void RegisterObserver(IObserver<T> & observer, int priority) = 0;
	virtual void RemoveObserver(IObserver<T> & observer) = 0;
};

template <class T>
class CObservable : public IObservable<T>
{
public:
	typedef IObserver<T> ObserverType;

	void RegisterObserver(ObserverType & observer, int priority) override
	{
		auto pair = m_priorityToObservers.insert({ priority, {} });
		pair.first->second.insert(&observer);
		m_observerToPriority[&observer] = priority;
		observer.m_subject = this;
	}

	void RemoveObserver(ObserverType & observer) override
	{
		auto it = m_observerToPriority.find(&observer);
		if (it != m_observerToPriority.end())
		{
			int priority = it->second;
			m_priorityToObservers[priority].erase(&observer);
			m_observerToPriority.erase(it);
			observer.m_subject = nullptr;
		}
	}

protected:
	void NotifyObservers()
	{
		T data = GetChangedData();

		auto observersCopy = m_priorityToObservers;
		for (auto it = observersCopy.rbegin(); it != observersCopy.rend(); ++it)
		{
			for (auto& observer : it->second)
			{
				observer->Update(data, this);
			}
		}
	}

	virtual T GetChangedData() const = 0;

private:
	std::map<int, std::unordered_set<ObserverType*>> m_priorityToObservers{};
	std::unordered_map<ObserverType*, int> m_observerToPriority{};
};
