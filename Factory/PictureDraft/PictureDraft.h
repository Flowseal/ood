#pragma once
#include "../Shapes/Shape.h"

class PictureDraft
{
public:
	const Shape& GetShape(size_t index) const
	{
		return *m_shapes[index];
	}

	void AddShape(std::unique_ptr<Shape> shape) 
	{ 
		m_shapes.push_back(std::move(shape));
	}

	size_t GetShapeCount() const { return m_shapes.size(); }

private:
	std::vector<std::unique_ptr<Shape>> m_shapes;
};