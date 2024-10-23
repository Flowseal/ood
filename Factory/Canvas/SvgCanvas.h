#pragma once
#include "ICanvas.h"
#include "svg.h"

class SvgCanvas : public ICanvas
{
public:
	void SetColor(Color color) override { m_color = color; }

	void DrawLine(Vec2 from, Vec2 to) override
	{
		m_root.add_child<SVG::Line>(from.x, to.x, from.y, to.y)->
			set_attr("style", "stroke: " + colorToString.at(m_color));
	}

	void DrawEllipse(int x, int y, int horizontalRadius, int verticalRadius) override
	{
		m_root.add_child<SVG::Ellipse>(x, y, horizontalRadius, verticalRadius)->
			set_attr("style", "stroke: " + colorToString.at(m_color)).
			set_attr("fill", "rgba(0,0,0,0)");
	}

	void SaveToFile(const std::string& fileName) override
	{
		m_root.autoscale();

		std::ofstream outfile(fileName);
		outfile << std::string(m_root);

		m_root = SVG::SVG{};
	}

private:
	Color m_color;
	SVG::SVG m_root;
};