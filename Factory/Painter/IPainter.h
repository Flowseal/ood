#pragma once
#include "../PictureDraft/PictureDraft.h"

class IPainter
{
public:
	virtual void DrawPicture(const PictureDraft& draft, ICanvas& canvas) const = 0;
	virtual ~IPainter() = default;
};