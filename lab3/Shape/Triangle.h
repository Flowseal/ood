#ifndef LAB1_TRIANGLE_H
#define LAB1_TRIANGLE_H

#include "../Visitor/IShapeVisitor.h"
#include "IShape.h"
#include <SFML/Graphics.hpp>

class Triangle : public IShape
{
public:
    Triangle(const sf::Vector2f& point1, const sf::Vector2f& point2, const sf::Vector2f& point3)
        : m_point1(point1)
        , m_point2(point2)
        , m_point3(point3)
    {
        m_convex.setPointCount(3);
        m_convex.setPoint(0, m_point1);
        m_convex.setPoint(1, m_point2);
        m_convex.setPoint(2, m_point3);
        m_convex.setFillColor(sf::Color::Blue);
    }

    std::string getType() const override
    {
        return "TRIANGLE";
    }

    void draw(sf::RenderWindow& window) const override
    {
        window.draw(m_convex);
    }

    void accept(IShapeVisitor& visitor) const override
    {
        visitor.visitTriangle(*this);
    }

    const sf::Vector2f& getPoint1() const { return m_point1; }
    const sf::Vector2f& getPoint2() const { return m_point2; }
    const sf::Vector2f& getPoint3() const { return m_point3; }

private:
    sf::ConvexShape m_convex;
    sf::Vector2f m_point1, m_point2, m_point3;
};

#endif // LAB1_TRIANGLE_H
