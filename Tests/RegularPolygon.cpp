#include "../Factory/Shapes/RegularPolygon.h"
#include "MockCanvas.h"
#include "pch.h"

#define M_PI 3.14159265358979323846

TEST(TestShape, RegularPolygon)
{
	EXPECT_THROW(RegularPolygon(Color::Red, Vec2(50, 50), 10, -3), std::invalid_argument);
	EXPECT_THROW(RegularPolygon(Color::Red, Vec2(50, 50), 10, 2), std::invalid_argument);

	MockCanvas canvas;
	RegularPolygon regularPolygon(Color::Red, Vec2(50, 50), 10, 3);

	EXPECT_EQ(regularPolygon.GetColor(), Color::Red);
	EXPECT_EQ(regularPolygon.GetCenter(), Vec2(50, 50));
	EXPECT_EQ(regularPolygon.GetRadius(), 10);
	EXPECT_EQ(regularPolygon.GetVertexCount(), 3);

	EXPECT_CALL(canvas, SetColor(Color::Red)).Times(1);

	const double angleSize = 2 * M_PI / 3;

	for (double i = 0; i < 2 * M_PI; i += angleSize)
	{
		int x1 = 50 + 10 * cos(i);
		int y1 = 50 + 10 * sin(i);
		int x2 = 50 + 10 * cos(i + angleSize);
		int y2 = 50 + 10 * sin(i + angleSize);

		EXPECT_CALL(canvas, DrawLine(Vec2(x1, y1), Vec2(x2, y2))).Times(1);
	}

	regularPolygon.Draw(canvas);
}