#ifndef LAB1_RECTANGLE_H
#define LAB1_RECTANGLE_H

#include "IShape.h"
#include <SFML/Graphics.hpp>

class Rectangle : public IShape
{
public:
    Rectangle(const sf::Vector2f& point1, const sf::Vector2f& point2)
        : m_point1(point1)
        , m_point2(point2)
    {
        auto size = sf::Vector2f(std::abs(m_point2.x - m_point1.x), std::abs(m_point2.y - m_point1.y));
        m_rectangle.setSize(size);
        m_rectangle.setPosition({ std::min(m_point1.x, m_point2.x), std::min(m_point1.y, m_point2.y) });
        m_rectangle.setFillColor(sf::Color::Green);
    }

    float calculatePerimeter() const override
    {
        return 2 * (std::abs(m_point2.x - m_point1.x) + std::abs(m_point2.y - m_point1.y));
    }

    float calculateArea() const override
    {
        return std::abs((m_point2.x - m_point1.x) * (m_point2.y - m_point1.y));
    }

    std::string getType() const override
    {
        return "RECTANGLE";
    }

    void draw(sf::RenderWindow& window) const override
    {
        window.draw(m_rectangle);
    }

private:
    sf::RectangleShape m_rectangle;
    sf::Vector2f m_point1, m_point2;
};

#endif // LAB1_RECTANGLE_H
