#pragma once
#include "../Shapes/Shape.h"

class IShapeFactory
{
public:
	virtual std::unique_ptr<Shape> CreateShape(const std::string& descr) const = 0;
	virtual ~IShapeFactory() = default;
};