#include "pch.h"
#include "../4/WeatherData.h"

class MockDisplay : public IObserver<SWeatherInfo>
{
public:
	MOCK_METHOD(void, Update, (const SWeatherInfo& data, const CObservable<SWeatherInfo>* observable), (override));

	MockDisplay() = default;
};

TEST(observer_test4, duo_observable_success)
{
	CWeatherData weatherDataIn;
	CWeatherData weatherDataOut;
	MockDisplay mockDisplay;

	weatherDataIn.RegisterObserver(mockDisplay, 1);
	weatherDataOut.RegisterObserver(mockDisplay, 2);

	EXPECT_CALL(mockDisplay, Update(testing::_, &weatherDataIn)).Times(1);
	EXPECT_CALL(mockDisplay, Update(testing::_, &weatherDataOut)).Times(1);

	weatherDataIn.SetMeasurements(1, 2, 3);
	weatherDataOut.SetMeasurements(4, 5, 6);
}