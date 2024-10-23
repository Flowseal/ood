#include "pch.h"
#include "MockCanvas.h"
#include "../Factory/Shapes/Ellipse.h"

TEST(TestShape, Ellipse)
{
	MockCanvas canvas;
	Ellipse ellipse(Color::Red, Vec2(50, 50), 10, 20);

	EXPECT_EQ(ellipse.GetColor(), Color::Red);
	EXPECT_EQ(ellipse.GetCenter(), Vec2(50, 50));
	EXPECT_EQ(ellipse.GetHorizontalRadius(), 10);
	EXPECT_EQ(ellipse.GetVerticalRadius(), 20);

	EXPECT_CALL(canvas, SetColor(Color::Red)).Times(1);
	EXPECT_CALL(canvas, DrawEllipse(50, 50, 10, 20)).Times(1);

	ellipse.Draw(canvas);
}