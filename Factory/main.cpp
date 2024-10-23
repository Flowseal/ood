#include "pcl.h"
#include "Painter/Painter.h"
#include "Canvas/SvgCanvas.h"
#include "ShapeFactory/ShapeFactory.h"
#include "Designer/Designer.h"
#include "Client/Client.h"

int main() 
{
	SvgCanvas canvas;
	Painter painter;
	ShapeFactory shapeFactory;
	Designer designer(shapeFactory);

	Client client(designer);
	client.OrderPictureByDescription(std::cin, painter, canvas);

	return 0;
}