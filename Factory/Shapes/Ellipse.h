#pragma once
#include "Shape.h"
#include "../Utils/Vec2.h"

class Ellipse : public Shape
{
public:
	Ellipse(Color color, Vec2 center, int horizontalRadius, int verticalRadius)
		: Shape(color)
		, m_center(center)
		, m_horizontalRadius(horizontalRadius)
		, m_verticalRadius(verticalRadius){};

	void Draw(ICanvas& canvas) const override
	{
		canvas.SetColor(m_color);
		canvas.DrawEllipse(m_center.x, m_center.y, m_horizontalRadius, m_verticalRadius);
	};

	Vec2 GetCenter() const { return m_center; };
	int GetHorizontalRadius() const { return m_horizontalRadius; };
	int GetVerticalRadius() const { return m_verticalRadius; };
	static const std::string GetTypeName() { return "Ellipse"; };

private:
	Vec2 m_center;
	int m_horizontalRadius;
	int m_verticalRadius;
};