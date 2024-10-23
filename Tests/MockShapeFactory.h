#pragma once
#include "pch.h"
#include "../Factory/ShapeFactory/IShapeFactory.h"

class MockShapeFactory : public IShapeFactory
{
public:
	MOCK_METHOD(std::unique_ptr<Shape>, CreateShape, (const std::string&), (const, override));
};