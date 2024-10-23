#pragma once
#include "pch.h"
#include "../Factory/Designer/IDesigner.h"

class MockDesigner : public IDesigner
{
public:
	MOCK_METHOD(PictureDraft, CreateDraft, (std::istream& stream), (override, const));
};