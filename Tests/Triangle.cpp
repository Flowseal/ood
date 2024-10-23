#include "../Factory/Shapes/Triangle.h"
#include "MockCanvas.h"
#include "pch.h"

TEST(TestShape, Triangle)
{
	MockCanvas canvas;
	Triangle triangle(Color::Red, Vec2(50, 50), Vec2(55, 55), Vec2(60, 50));

	EXPECT_EQ(triangle.GetColor(), Color::Red);
	EXPECT_EQ(triangle.GetPoint1(), Vec2(50, 50));
	EXPECT_EQ(triangle.GetPoint2(), Vec2(55, 55));
	EXPECT_EQ(triangle.GetPoint3(), Vec2(60, 50));

	EXPECT_CALL(canvas, SetColor(Color::Red)).Times(1);
	EXPECT_CALL(canvas, DrawLine(Vec2(50, 50), Vec2(55, 55))).Times(1);
	EXPECT_CALL(canvas, DrawLine(Vec2(55, 55), Vec2(60, 50))).Times(1);
	EXPECT_CALL(canvas, DrawLine(Vec2(60, 50), Vec2(50, 50))).Times(1);

	triangle.Draw(canvas);
}