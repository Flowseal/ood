#pragma once
#include "pch.h"
#include "../Factory/Painter/IPainter.h"

class MockPainter : public IPainter
{
public:
	MOCK_METHOD(void, DrawPicture, (const PictureDraft& draft, ICanvas& canvas), (const, override));
};