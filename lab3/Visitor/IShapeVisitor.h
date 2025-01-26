#ifndef LAB3_ISHAPEVISITOR_H
#define LAB3_ISHAPEVISITOR_H

class Circle;
class Rectangle;
class Triangle;

class IShapeVisitor
{
public:
    virtual ~IShapeVisitor() = default;
    virtual void visitCircle(const Circle& circle) = 0;
    virtual void visitRectangle(const Rectangle& rectangle) = 0;
    virtual void visitTriangle(const Triangle& triangle) = 0;
};

#endif
