#include <iostream>
#include <string>

#include "libs/graphics_lib.h"
#include "libs/modern_graphics_lib.h"
#include "libs/shape_drawing_lib.h"
#include "adapters/ModernGraphicsClassAdapter.h"
#include "adapters/ModernGraphicsObjectAdapter.h"

namespace app
{
void PaintPicture(shape_drawing_lib::CCanvasPainter& painter)
{
	using namespace shape_drawing_lib;

	const CTriangle triangle({ 10, 15 }, { 100, 200 }, { 150, 250 });
	const CRectangle rectangle({ 30, 40 }, 18, 24, 0xFF0000);

	painter.Draw(triangle);
	painter.Draw(rectangle);
}

void PaintPictureOnCanvas()
{
	graphics_lib::CCanvas simpleCanvas;
	shape_drawing_lib::CCanvasPainter painter(simpleCanvas);

	PaintPicture(painter);
}

void PaintPictureOnModernGraphicsRenderer()
{
	modern_graphics_lib::CModernGraphicsRenderer renderer(std::cout);
	CModernGraphicsToGraphicsObjectAdapter adaptedModernRenderer(renderer);
	shape_drawing_lib::CCanvasPainter painter(adaptedModernRenderer);

	renderer.BeginDraw();
	PaintPicture(painter);
	renderer.EndDraw();
}

//void PaintPictureOnModernGraphicsRenderer()
//{
//	CModernGraphicsToGraphicsClassAdapter adaptedModernRenderer(std::cout);
//	shape_drawing_lib::CCanvasPainter painter(adaptedModernRenderer);
//
//	adaptedModernRenderer.BeginDraw();
//	PaintPicture(painter);
//	adaptedModernRenderer.EndDraw();
//}
} // namespace app

int main()
{
	std::cout << "Should we use new API (y)?";

	std::string userInput;

	if (std::getline(std::cin, userInput) && (userInput == "y" || userInput == "Y"))
	{
		app::PaintPictureOnModernGraphicsRenderer();
	}
	else
	{
		app::PaintPictureOnCanvas();
	}

	return 0;
}