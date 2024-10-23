#pragma once
#include "pch.h"
#include "../Factory/Shapes/Shape.h"

class MockShape : public Shape
{
public:
	MockShape(Color color)
		: Shape(color) {}

	MOCK_METHOD(void, Draw, (ICanvas& canvas), (const, override));
};