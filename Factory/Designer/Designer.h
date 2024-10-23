#pragma once
#include "IDesigner.h"
#include "../ShapeFactory/IShapeFactory.h"

class Designer : public IDesigner
{
public:
	Designer(IShapeFactory& shapeFactory)
		: m_shapesFactory(shapeFactory) {};

	PictureDraft CreateDraft(std::istream& stream) const override
	{
		PictureDraft pictureDraft;

		std::string lineDescr;
		while (getline(stream, lineDescr))
		{
			pictureDraft.AddShape(std::move(m_shapesFactory.CreateShape(lineDescr)));
		}

		return pictureDraft;
	};

private:
	IShapeFactory& m_shapesFactory;
};