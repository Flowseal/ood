#pragma once
#include "pch.h"
#include "../Factory/Canvas/ICanvas.h"

class MockCanvas : public ICanvas
{
public:
	MOCK_METHOD(void, SetColor, (Color color), (override));

	MOCK_METHOD(void, DrawLine, (Vec2 from, Vec2 to), (override));

	MOCK_METHOD(void, DrawEllipse, (int x, int y, int width, int height), (override));

	MOCK_METHOD(void, SaveToFile, (const std::string& fileName), (override));
};