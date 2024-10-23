#pragma once
#include "IPainter.h"

class Painter : public IPainter
{
public:
	void DrawPicture(const PictureDraft& draft, ICanvas& canvas) const override
	{
		const size_t shapesCount = draft.GetShapeCount();

		for (int i = 0; i < shapesCount; ++i)
		{
			const auto& shape = draft.GetShape(i);
			shape.Draw(canvas);
		}

		canvas.SaveToFile("output.svg");
	};
};