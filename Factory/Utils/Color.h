#pragma once
#include "../pcl.h"

enum class Color
{
	Red,
	Green,
	Blue,
	Pink,
	Yellow,
	Black
};

static const std::unordered_map<std::string, Color> stringToColor = 
{
	{ "red", Color::Red },
	{ "green", Color::Green },
	{ "blue", Color::Blue },
	{ "pink", Color::Pink },
	{ "yellow", Color::Yellow },
	{ "black", Color::Black },
};

static const std::unordered_map<Color, std::string> colorToString = {
	{ Color::Red, "red" },
	{ Color::Green, "green" },
	{ Color::Blue, "blue" },
	{ Color::Pink, "pink" },
	{ Color::Yellow, "yellow" },
	{ Color::Black , "black" },
};