#pragma once
#include "../Shapes/Shape.h"
#include "../Utils/Vec2.h"

class Rectangle : public Shape
{
public:
	Rectangle(Color color, Vec2 leftTop, Vec2 rightBottom)
		: Shape(color)
		, m_leftTop(leftTop)
		, m_rightBottom(rightBottom){};

	void Draw(ICanvas& canvas) const override
	{
		canvas.SetColor(m_color);

		canvas.DrawLine(m_leftTop, Vec2(m_rightBottom.x, m_leftTop.y));
		canvas.DrawLine(Vec2(m_rightBottom.x, m_leftTop.y), m_rightBottom);
		canvas.DrawLine(m_rightBottom, Vec2(m_leftTop.x, m_rightBottom.y));
		canvas.DrawLine(Vec2(m_leftTop.x, m_rightBottom.y), m_leftTop);
	};

	Vec2 GetLeftTop() const { return m_leftTop; }
	Vec2 GetRightBottom() const { return m_rightBottom; }
	static const std::string GetTypeName() { return "Rectangle"; };

private:
	Vec2 m_leftTop;
	Vec2 m_rightBottom;
};