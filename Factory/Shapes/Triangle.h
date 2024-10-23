#pragma once
#include "Shape.h"
#include "../Utils/Vec2.h"

class Triangle : public Shape
{
public:
	Triangle(Color color, Vec2 vertex1, Vec2 vertex2, Vec2 vertex3)
		: Shape(color)
		, m_vertex1(vertex1)
		, m_vertex2(vertex2)
		, m_vertex3(vertex3) {};

	void Draw(ICanvas& canvas) const override
	{
		canvas.SetColor(m_color);
		canvas.DrawLine(m_vertex1, m_vertex2);
		canvas.DrawLine(m_vertex2, m_vertex3);
		canvas.DrawLine(m_vertex3, m_vertex1);
	};

	Vec2 GetPoint1() const { return m_vertex1; }
	Vec2 GetPoint2() const { return m_vertex2; }
	Vec2 GetPoint3() const { return m_vertex3; }

	static const std::string GetTypeName() { return "Triangle"; };

private:
	Vec2 m_vertex1;
	Vec2 m_vertex2;
	Vec2 m_vertex3;
};