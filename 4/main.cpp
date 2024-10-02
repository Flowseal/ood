#include "WeatherData.h"

int main()
{
	CWeatherData weatherDataIn;
	CWeatherData weatherDataOut;

	CDisplay display;
	weatherDataIn.RegisterObserver(display, 100);
	weatherDataOut.RegisterObserver(display, 200);
	display.SetInsideSensor(&weatherDataIn);
	display.SetOutsideSensor(&weatherDataOut);

	CStatsDisplay statsDisplay;
	weatherDataOut.RegisterObserver(statsDisplay, 1);

	weatherDataIn.SetMeasurements(3, 0.7, 760);
	weatherDataOut.SetMeasurements(4, 0.8, 761);
	return 0;
}