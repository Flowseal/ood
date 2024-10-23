#pragma once
#include "../pcl.h"
#include "../Utils/Vec2.h"
#include "../Utils/Color.h"

class ICanvas
{
public:
	virtual void SetColor(Color color) = 0;
	virtual void DrawLine(Vec2 from, Vec2 to) = 0;
	virtual void DrawEllipse(int x, int y, int w, int h) = 0;
	virtual void SaveToFile(const std::string& fileName) = 0;

	virtual ~ICanvas() = default;
};