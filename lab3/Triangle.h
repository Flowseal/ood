#ifndef LAB1_TRIANGLE_H
#define LAB1_TRIANGLE_H

#include "IShape.h"
#include "IShapeVisitor.h"
#include <SFML/Graphics.hpp>

class Triangle : public IShape
{
public:
    Triangle(const sf::Vector2f& point1, const sf::Vector2f& point2, const sf::Vector2f& point3)
        : m_point1(point1)
        , m_point2(point2)
        , m_point3(point3)
    {
        m_shape.setPointCount(3);
        m_shape.setPoint(0, m_point1);
        m_shape.setPoint(1, m_point2);
        m_shape.setPoint(2, m_point3);
        m_shape.setFillColor(sf::Color::Blue);
    }

    void accept(IShapeVisitor& visitor) const override
    {
        visitor.visitTriangle(*this);
    }

    std::string getType() const override
    {
        return "TRIANGLE";
    }

    void draw(sf::RenderWindow& window) const override
    {
        window.draw(m_shape);
    }

    const sf::Vector2f& getPoint1() const { return m_point1; }
    const sf::Vector2f& getPoint2() const { return m_point2; }
    const sf::Vector2f& getPoint3() const { return m_point3; }

private:
    sf::ConvexShape m_shape;
    sf::Vector2f m_point1, m_point2, m_point3;
};

#endif // LAB1_TRIANGLE_H
