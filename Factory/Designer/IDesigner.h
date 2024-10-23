#pragma once
#include "../PictureDraft/PictureDraft.h"

class IDesigner
{
public:
	virtual PictureDraft CreateDraft(std::istream& stream) const = 0;
	virtual ~IDesigner() = default;
};