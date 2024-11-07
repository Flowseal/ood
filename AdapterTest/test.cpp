#include "../Adapter/adapters/ModernGraphicsClassAdapter.h"
#include "../Adapter/adapters/ModernGraphicsObjectAdapter.h"
#include "../Adapter/libs/graphics_lib.h"
#include "../Adapter/libs/modern_graphics_lib.h"
#include "../Adapter/libs/shape_drawing_lib.h"
#include "pch.h"
#include <sstream>

TEST(AdapterTest, ConstructorClassAdapter)
{
	std::stringstream output;

	{
		CModernGraphicsToGraphicsClassAdapter adapter(output);
		adapter.LineTo(5, 5);
	}

	std::string expected_output = R"(<draw>
<line fromX="0" fromY="0" toX="5" toY="5">
	<color r="0" g="0" b="0" a="1" />
</line>
</draw>
)";

	EXPECT_EQ(output.str(), expected_output);
}

TEST(AdapterTest, ConstructorObjectAdapter)
{
	std::stringstream output;

	{
		modern_graphics_lib::CModernGraphicsRenderer renderer(output);
		CModernGraphicsToGraphicsObjectAdapter adapter(renderer);

		adapter.LineTo(5, 5);
	}

	std::string expected_output = R"(<draw>
<line fromX="0" fromY="0" toX="5" toY="5">
	<color r="0" g="0" b="0" a="1" />
</line>
</draw>
)";

	EXPECT_EQ(output.str(), expected_output);
}

TEST(AdapterTest, DrawTriangleWithClassAdapter)
{
	std::stringstream output;

	{
		CModernGraphicsToGraphicsClassAdapter adapter(output);

		shape_drawing_lib::Point p1{ 0, 0 }, p2{ 10, 0 }, p3{ 5, 5 };
		shape_drawing_lib::CTriangle triangle(p1, p2, p3, 0xFF6600FF);
		triangle.Draw(adapter);
	}

	std::string expected_output = R"(<draw>
<line fromX="0" fromY="0" toX="10" toY="0">
	<color r="1" g="0.4" b="0" a="1" />
</line>
<line fromX="10" fromY="0" toX="5" toY="5">
	<color r="1" g="0.4" b="0" a="1" />
</line>
<line fromX="5" fromY="5" toX="0" toY="0">
	<color r="1" g="0.4" b="0" a="1" />
</line>
</draw>
)";

	EXPECT_EQ(output.str(), expected_output);
}

TEST(AdapterTest, DrawTriangleWithObjectAdapter)
{
	std::stringstream output;

	{
		modern_graphics_lib::CModernGraphicsRenderer renderer(output);
		CModernGraphicsToGraphicsObjectAdapter adapter(renderer);

		shape_drawing_lib::Point p1{ 0, 0 }, p2{ 10, 0 }, p3{ 5, 5 };
		shape_drawing_lib::CTriangle triangle(p1, p2, p3, 0xFF6600FF);
		triangle.Draw(adapter);
	}

	std::string expected_output = R"(<draw>
<line fromX="0" fromY="0" toX="10" toY="0">
	<color r="1" g="0.4" b="0" a="1" />
</line>
<line fromX="10" fromY="0" toX="5" toY="5">
	<color r="1" g="0.4" b="0" a="1" />
</line>
<line fromX="5" fromY="5" toX="0" toY="0">
	<color r="1" g="0.4" b="0" a="1" />
</line>
</draw>
)";

	EXPECT_EQ(output.str(), expected_output);
}