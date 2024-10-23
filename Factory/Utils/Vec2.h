#pragma once

struct Vec2
{
	int x;
	int y;

	Vec2(int x_, int y_)
		: x(x_)
		, y(y_) {}
};

inline bool operator==(const Vec2& lhs, const Vec2& rhs)
{
	return lhs.x == rhs.x
		&& lhs.y == rhs.y;
}