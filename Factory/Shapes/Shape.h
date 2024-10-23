#pragma once
#include "../Utils/Color.h"
#include "../Canvas/ICanvas.h"

class Shape
{
public:
	Shape(const Color color)
		: m_color(color) {}

	virtual void Draw(ICanvas& canvas) const = 0;
	Color GetColor() const { return m_color; }

	virtual ~Shape() = default;

protected:
	Color m_color;
};