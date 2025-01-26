
#ifndef LAB1_TRIANGLE_H
#define LAB1_TRIANGLE_H

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

    float calculatePerimeter() const override
    {
        auto calculateDistance = [](const sf::Vector2f& a, const sf::Vector2f& b) {
            return std::sqrtf(std::powf(b.x - a.x, 2) + std::powf(b.y - a.y, 2));
        };
        return calculateDistance(m_point1, m_point2)
            + calculateDistance(m_point2, m_point3)
            + calculateDistance(m_point3, m_point1);
    }

    float calculateArea() const override
    {
        return std::abs((
                   m_point1.x * (m_point2.y - m_point3.y)
                   + m_point2.x * (m_point3.y - m_point1.y)
                   + m_point3.x * (m_point1.y - m_point2.y)))
            / 2.0f;
    }

    std::string getType() const override
    {
        return "TRIANGLE";
    }

    void draw(sf::RenderWindow& window) const override
    {
        window.draw(m_convex);
    }

private:
    sf::ConvexShape m_convex;
    sf::Vector2f m_point1, m_point2, m_point3;
};

#endif // LAB1_TRIANGLE_H
