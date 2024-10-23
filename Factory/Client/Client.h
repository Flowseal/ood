#pragma once
#include "../Designer/IDesigner.h"
#include "../Painter/IPainter.h"

class Client
{
public:
	Client(IDesigner& designer)
		: m_designer(designer){};

	void OrderPictureByDescription(std::istream& stream, IPainter& painter, ICanvas& canvas)
	{
		PictureDraft draft = m_designer.CreateDraft(stream);
		OrderPictureByDraft(draft, painter, canvas);
	};

	void OrderPictureByDraft(const PictureDraft& draft, IPainter& painter, ICanvas& canvas)
	{
		painter.DrawPicture(draft, canvas);
	};

private:
	IDesigner& m_designer;
};