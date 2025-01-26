#ifndef LAB2_TRIANGLECREATOR_H
#define LAB2_TRIANGLECREATOR_H

#include "../Shape/Triangle.h"
#include "IShapeCreator.h"

class TriangleCreator : public IShapeCreator
{
public:
    static TriangleCreator& getInstance()
    {
        static TriangleCreator instance;
        return instance;
    }

    std::unique_ptr<IShape> createShape() const override
    {
        return std::make_unique<Triangle>(m_point1, m_point2, m_point3);
    }

    void setParameters(const sf::Vector2f& point1, const sf::Vector2f& point2, const sf::Vector2f& point3)
    {
        m_point1 = point1;
        m_point2 = point2;
        m_point3 = point3;
    }

private:
    TriangleCreator() = default;
    sf::Vector2f m_point1, m_point2, m_point3;
};

#endif // LAB2_TRIANGLECREATOR_H
