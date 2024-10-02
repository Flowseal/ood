#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include "Observer.h"

struct SWeatherInfo
{
	double temperature = 0;
	double humidity = 0;
	double pressure = 0;
};

class CStat
{
public:
	void Update(double newValue)
	{
		if (m_min > newValue)
		{
			m_min = newValue;
		}
		if (m_max < newValue)
		{
			m_max = newValue;
		}
		m_summary += newValue;
		++m_count;
	}

	double GetMin() const
	{
		return m_min;
	}

	double GetMax() const
	{
		return m_max;
	}

	double GetAvg() const
	{
		return m_summary / static_cast<double>(m_count);
	}

	void Display(const std::string& statName) const
	{
		std::cout << "Min " << statName << ": " << m_min << std::endl;
		std::cout << "Max " << statName << ": " << m_max << std::endl;
		std::cout << "Average " << statName << ": " << GetAvg() << std::endl;
		std::cout << "----------------" << std::endl;
	}

private:
	double m_min = std::numeric_limits<double>::infinity();
	double m_max = -std::numeric_limits<double>::infinity();
	double m_summary = 0;
	unsigned int m_count = 0;
};

class CDuoWeather : public IObserver<SWeatherInfo>
{
public:
	void SetInsideSensor(CObservable<SWeatherInfo>* weatherDataIn)
	{
		m_weatherDataIn = weatherDataIn;
	}

	void SetOutsideSensor(CObservable<SWeatherInfo>* weatherDataOut)
	{
		m_weatherDataOut = weatherDataOut;
	}

protected:
	CObservable<SWeatherInfo>* m_weatherDataIn;
	CObservable<SWeatherInfo>* m_weatherDataOut;
};

class CDisplay : public CDuoWeather
{
private:
	/* Метод Update сделан приватным, чтобы ограничить возможность его вызова напрямую
		Классу CObservable он будет доступен все равно, т.к. в интерфейсе IObserver он
		остается публичным
	*/
	void Update(SWeatherInfo const& data, const CObservable<SWeatherInfo>* observable) override
	{
		std::string location;
		if (observable == m_weatherDataIn)
		{
			location = "[in]";
		}
		else if (observable == m_weatherDataOut)
		{
			location = "[out]";
		}
		else
		{
			location = "[undefined]";
		}

		std::cout << location << std::endl;
		std::cout << "Current Temp " << data.temperature << std::endl;
		std::cout << "Current Hum " << data.humidity << std::endl;
		std::cout << "Current Pressure " << data.pressure << std::endl;
		std::cout << "----------------" << std::endl;
	}
};

class CStatsDisplay : public CDuoWeather
{
private:
	/* Метод Update сделан приватным, чтобы ограничить возможность его вызова напрямую
	Классу CObservable он будет доступен все равно, т.к. в интерфейсе IObserver он
	остается публичным
	*/
	void Update(SWeatherInfo const& data, const CObservable<SWeatherInfo>* observable) override
	{
		m_temperature.Update(data.temperature);
		m_humidity.Update(data.humidity);
		m_pressure.Update(data.pressure);

		m_temperature.Display("Temperature");
		m_humidity.Display("Humidity");
		m_pressure.Display("Pressure");
	}

	CStat m_temperature;
	CStat m_humidity;
	CStat m_pressure;
};

class CWeatherData : public CObservable<SWeatherInfo>
{
public:
	// Температура в градусах Цельсия
	double GetTemperature() const
	{
		return m_temperature;
	}
	// Относительная влажность (0...100)
	double GetHumidity() const
	{
		return m_humidity;
	}
	// Атмосферное давление (в мм.рт.ст)
	double GetPressure() const
	{
		return m_pressure;
	}

	void MeasurementsChanged()
	{
		NotifyObservers();
	}

	void SetMeasurements(double temp, double humidity, double pressure)
	{
		m_humidity = humidity;
		m_temperature = temp;
		m_pressure = pressure;

		MeasurementsChanged();
	}
protected:
	SWeatherInfo GetChangedData() const override
	{
		SWeatherInfo info;
		info.temperature = GetTemperature();
		info.humidity = GetHumidity();
		info.pressure = GetPressure();
		return info;
	}
private:
	double m_temperature = 0.0;
	double m_humidity = 0.0;	
	double m_pressure = 760.0;	
};
