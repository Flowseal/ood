#ifndef LAB3_SHAPEPARAMETERSVISITOR_H
#define LAB3_SHAPEPARAMETERSVISITOR_H

#include "../Shape/Circle.h"
#include "../Shape/Rectangle.h"
#include "../Shape/Triangle.h"
#include "IShapeVisitor.h"

class ShapeParametersVisitor : public IShapeVisitor
{
public:
    void visitCircle(const Circle& circle) override
    {
        const auto& radius = circle.getRadius();

        m_perimeter = 2 * 3.14f * radius;
        m_area = 3.14f * radius * radius;
    }

    void visitRectangle(const Rectangle& rectangle) override
    {
        const auto& point1 = rectangle.getPoint1();
        const auto& point2 = rectangle.getPoint2();

        m_perimeter = 2 * (std::abs(point2.x - point1.x) + std::abs(point2.y - point1.y));
        m_area = std::abs((point2.x - point1.x) * (point2.y - point1.y));
    }

    void visitTriangle(const Triangle& triangle) override
    {
        const auto& point1 = triangle.getPoint1();
        const auto& point2 = triangle.getPoint2();
        const auto& point3 = triangle.getPoint3();

        auto calculateDistance = [](const sf::Vector2f& a, const sf::Vector2f& b) {
            return std::sqrtf(std::powf(b.x - a.x, 2) + std::powf(b.y - a.y, 2));
        };

        m_perimeter = calculateDistance(point1, point2) + calculateDistance(point2, point3) + calculateDistance(point3, point1);
        m_area = std::abs((point1.x * (point2.y - point3.y) + point2.x * (point3.y - point1.y) + point3.x * (point1.y - point2.y))) / 2.0f;
    }

    float getPerimeter() const { return m_perimeter; }
    float getArea() const { return m_area; }

private:
    float m_perimeter = 0.f;
    float m_area = 0.f;
};

#endif
