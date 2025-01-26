#ifndef LAB2_ISHAPECREATOR_H
#define LAB2_ISHAPECREATOR_H

#include "../Shape/IShape.h"

class IShapeCreator
{
public:
    virtual ~IShapeCreator() = default;
    virtual std::unique_ptr<IShape> createShape() const = 0;

protected:
    IShapeCreator() = default;
};

#endif // LAB2_ISHAPECREATOR_H
