#pragma once

#include <set>

template <typename T>
class IObservable;

template <typename T>
class CObservable;

/*
Шаблонный интерфейс IObserver. Его должен реализовывать класс, 
желающий получать уведомления от соответствующего IObservable
Параметром шаблона является тип аргумента,
передаваемого Наблюдателю в метод Update
*/
template <typename T>
class IObserver
{
public:
	virtual ~IObserver() = default;

protected:
	virtual void Update(T const& data) = 0;
	IObservable<T>* m_subject;

	friend class CObservable<T>;
};

/*
Шаблонный интерфейс IObservable. Позволяет подписаться и отписаться на оповещения, а также
инициировать рассылку уведомлений зарегистрированным наблюдателям.
*/
template <typename T>
class IObservable
{
public:
	virtual ~IObservable() = default;
	virtual void RegisterObserver(IObserver<T> & observer) = 0;
	virtual void RemoveObserver(IObserver<T> & observer) = 0;
};

// Реализация интерфейса IObservable
template <class T>
class CObservable : public IObservable<T>
{
public:
	typedef IObserver<T> ObserverType;

	void RegisterObserver(ObserverType & observer) override
	{
		m_observers.insert(&observer);
		observer.m_subject = this;
	}

	void RemoveObserver(ObserverType & observer) override
	{
		m_observers.erase(&observer);
		observer.m_subject = nullptr;
	}

protected:
	void NotifyObservers()
	{
		T data = GetChangedData();
		const auto observersCopy = m_observers;

		for (auto& observer : observersCopy)
		{
			observer->Update(data);
		}
	}

	// Классы-наследники должны перегрузить данный метод, 
	// в котором возвращать информацию об изменениях в объекте
	virtual T GetChangedData() const = 0;

private:
	std::set<ObserverType *> m_observers;
};
