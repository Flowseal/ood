#pragma once
#include "Shape.h"
#include "../Utils/Vec2.h"

#define M_PI 3.14159265358979323846

class RegularPolygon : public Shape
{
public:
	RegularPolygon(Color color, Vec2 center, int radius, int vertexCount)
		: Shape(color)
		, m_center(center)
		, m_radius(radius)
	{
		if (vertexCount <= 2)
		{
			throw std::invalid_argument("Polygon must have more than 2 vertexes");
		}

		m_vertexCount = vertexCount;
	};

	void Draw(ICanvas& canvas) const override
	{
		canvas.SetColor(m_color);

		const double angleSize = 2 * M_PI / m_vertexCount;

		for (double i = 0; i < 2 * M_PI; i += angleSize)
		{
			int x1 = m_center.x + m_radius * cos(i);
			int y1 = m_center.y + m_radius * sin(i);
			int x2 = m_center.x + m_radius * cos(i + angleSize);
			int y2 = m_center.y + m_radius * sin(i + angleSize);

			canvas.DrawLine(Vec2(x1, y1), Vec2(x2, y2));
		}
	};

	Vec2 GetCenter() const { return m_center; }
	int GetRadius() const { return m_radius; }
	int GetVertexCount() const { return m_vertexCount; }
	static const std::string GetTypeName() { return "RegularPolygon"; };

private:
	Vec2 m_center;
	int m_radius;
	int m_vertexCount;
};