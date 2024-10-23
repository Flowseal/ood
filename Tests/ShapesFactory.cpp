#include "pch.h"
#include "../Factory/ShapeFactory/ShapeFactory.h"

TEST(TestShapeFactory, Unknown)
{
	ShapeFactory factory;
	std::string description = "Tottallyunknownshape pink 50 50 50 50";
	EXPECT_THROW(factory.CreateShape(description), std::invalid_argument);
}


TEST(TestShapeFactory, Triangle)
{
	ShapeFactory factory;
	std::string description = "Triangle pink 50 50 55 55 60 50";
	EXPECT_NO_THROW(factory.CreateShape(description));
}

TEST(TestShapeFactory, Ellipse)
{
	ShapeFactory factory;
	std::string description = "Ellipse pink 50 50 15 20";
	EXPECT_NO_THROW(factory.CreateShape(description));
}

TEST(TestShapeFactory, Rectangle)
{
	ShapeFactory factory;
	std::string description = "Rectangle pink 50 50 60 60";
	EXPECT_NO_THROW(factory.CreateShape(description));
}

TEST(TestShapeFactory, RegularPolygon)
{
	ShapeFactory factory;
	std::string description = "RegularPolygon pink 50 50 10 5";
	EXPECT_NO_THROW(factory.CreateShape(description));
}