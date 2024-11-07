#pragma once
#include "../libs/graphics_lib.h"
#include "../libs/modern_graphics_lib.h"

class CModernGraphicsToGraphicsObjectAdapter : public graphics_lib::ICanvas
{
public:
	CModernGraphicsToGraphicsObjectAdapter(modern_graphics_lib::CModernGraphicsRenderer& modernRenderer)
		: m_renderer(modernRenderer)
		, m_pos(0, 0)
		, m_color(0.f, 0.f, 0.f, 1.f)
	{
		m_renderer.BeginDraw();
	}

	void SetColor(uint32_t rgbaColor) override
	{
		float r = ((rgbaColor >> 24) & 0xFF) / 255.0f;
		float g = ((rgbaColor >> 16) & 0xFF) / 255.0f;
		float b = ((rgbaColor >> 8) & 0xFF) / 255.0f;
		float a = (rgbaColor & 0xFF) / 255.0f;

		m_color = { r, g, b, a };
	}

	void MoveTo(int x, int y) override
	{
		m_pos = { x, y };
	}

	void LineTo(int x, int y) override
	{
		m_renderer.DrawLine(m_pos, { x, y }, m_color);
		m_pos = { x, y };
	}

private:
	modern_graphics_lib::CRGBAColor m_color;
	modern_graphics_lib::Point m_pos;
	modern_graphics_lib::CModernGraphicsRenderer& m_renderer;
};