#ifndef LAB1_CIRCLE_H
#define LAB1_CIRCLE_H

#include "IShape.h"
#include "IShapeVisitor.h"
#include <SFML/Graphics.hpp>

class Circle : public IShape
{
public:
    Circle(const sf::Vector2f& center, float radius)
        : m_center(center)
        , m_radius(radius)
    {
        m_circle.setPosition({ m_center.x - m_radius, m_center.y - m_radius });
        m_circle.setRadius(m_radius);
        m_circle.setFillColor(sf::Color::Red);
    }

    void accept(IShapeVisitor& visitor) const override
    {
        visitor.visitCircle(*this);
    }

    std::string getType() const override
    {
        return "CIRCLE";
    }

    void draw(sf::RenderWindow& window) const override
    {
        window.draw(m_circle);
    }

    float getRadius() const { return m_radius; }
    const sf::Vector2f& getCenter() const { return m_center; }

private:
    sf::CircleShape m_circle;
    sf::Vector2f m_center;
    float m_radius;
};

#endif // LAB1_CIRCLE_H
