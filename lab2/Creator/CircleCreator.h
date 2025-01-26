#ifndef LAB2_CIRCLECREATOR_H
#define LAB2_CIRCLECREATOR_H

#include "../Shape/Circle.h"
#include "IShapeCreator.h"

class CircleCreator : public IShapeCreator
{
public:
    static CircleCreator& getInstance()
    {
        static CircleCreator instance;
        return instance;
    }

    std::unique_ptr<IShape> createShape() const override
    {
        return std::make_unique<Circle>(m_center, m_radius);
    }

    void setParameters(const sf::Vector2f& center, float radius)
    {
        m_center = center;
        m_radius = radius;
    }

private:
    CircleCreator() = default;
    sf::Vector2f m_center;
    float m_radius;
};

#endif // LAB2_CIRCLECREATOR_H
