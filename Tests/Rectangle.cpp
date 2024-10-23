#include "../Factory/Shapes/Rectangle.h"
#include "MockCanvas.h"
#include "pch.h"

TEST(TestShape, Rectangle)
{
	MockCanvas canvas;
	Rectangle rectangle(Color::Red, Vec2(50, 50), Vec2(60, 60));

	EXPECT_EQ(rectangle.GetColor(), Color::Red);
	EXPECT_EQ(rectangle.GetLeftTop(), Vec2(50, 50));
	EXPECT_EQ(rectangle.GetRightBottom(), Vec2(60, 60));

	EXPECT_CALL(canvas, SetColor(Color::Red)).Times(1);
	EXPECT_CALL(canvas, DrawLine(Vec2(50, 50), Vec2(60, 50))).Times(1);
	EXPECT_CALL(canvas, DrawLine(Vec2(60, 50), Vec2(60, 60))).Times(1);
	EXPECT_CALL(canvas, DrawLine(Vec2(60, 60), Vec2(50, 60))).Times(1);
	EXPECT_CALL(canvas, DrawLine(Vec2(50, 60), Vec2(50, 50))).Times(1);

	rectangle.Draw(canvas);
}