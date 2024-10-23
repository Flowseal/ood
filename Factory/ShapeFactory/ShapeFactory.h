#pragma once
#include "IShapeFactory.h"
#include "../Shapes/Ellipse.h"
#include "../Shapes/Rectangle.h"
#include "../Shapes/Triangle.h"
#include "../Shapes/RegularPolygon.h"

class ShapeFactory : public IShapeFactory
{
public:
	std::unique_ptr<Shape> CreateShape(const std::string& descr) const override
	{
		std::istringstream iss(descr);

		std::string shapeType;
		iss >> shapeType;

		if (shapeType == Triangle::GetTypeName())
		{
			return CreateTriangle(iss);
		}
		else if (shapeType == Rectangle::GetTypeName())
		{
			return CreateRectangle(iss);
		}
		else if (shapeType == Ellipse::GetTypeName())
		{
			return CreateEllipse(iss);
		}
		else if (shapeType == RegularPolygon::GetTypeName())
		{
			return CreateRegularPolygon(iss);
		}
		else
		{
			throw std::invalid_argument("Unknown shape description");	
		}
	};

private:
	std::unique_ptr<Triangle> CreateTriangle(std::istringstream& iss) const
	{
		std::string color;
		std::string point1X, point1Y;
		std::string point2X, point2Y;
		std::string point3X, point3Y;

		iss >> color >> point1X >> point1Y >> point2X >> point2Y >> point3X >> point3Y;

		return std::make_unique<Triangle>(
			stringToColor.at(color),
			Vec2(std::stoi(point1X), std::stoi(point1Y)), 
			Vec2(std::stoi(point2X), std::stoi(point2Y)),
			Vec2(std::stoi(point3X), std::stoi(point3Y)));
	};

	std::unique_ptr<Rectangle> CreateRectangle(std::istringstream& iss) const
	{
		std::string color;
		std::string topLeftX, topLeftY;
		std::string bottomRightX, bottomRightY;

		iss >> color >> topLeftX >> topLeftY >> bottomRightX >> bottomRightY;

		return std::make_unique<Rectangle>(
			stringToColor.at(color), 
			Vec2(std::stoi(topLeftX), std::stoi(topLeftY)),
			Vec2(std::stoi(bottomRightX), std::stoi(bottomRightY)));
	};

	std::unique_ptr<Ellipse> CreateEllipse(std::istringstream& iss) const
	{
		std::string color;
		std::string centerX, centerY;
		std::string horizontalRadius, verticalRadius;

		iss >> color >> centerX >> centerY >> horizontalRadius >> verticalRadius;

		return std::make_unique<Ellipse>(
			stringToColor.at(color),
			Vec2(std::stoi(centerX), std::stoi(centerY)),
			std::stoi(horizontalRadius), std::stoi(verticalRadius));
	};

	std::unique_ptr<RegularPolygon> CreateRegularPolygon(std::istringstream& iss) const
	{
		std::string color;
		std::string centerX, centerY;
		std::string radius;
		std::string vertexCount;

		iss >> color >> centerX >> centerY >> radius >> vertexCount;

		return std::make_unique<RegularPolygon>(
			stringToColor.at(color),
			Vec2(std::stoi(centerX), std::stoi(centerY)), 
			std::stoi(radius), std::stoi(vertexCount));
	};

};