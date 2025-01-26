#ifndef LAB2_RECTANGLECREATOR_H
#define LAB2_RECTANGLECREATOR_H

#include "../Shape/Rectangle.h"
#include "IShapeCreator.h"

class RectangleCreator : public IShapeCreator
{
public:
    static RectangleCreator& getInstance()
    {
        static RectangleCreator instance;
        return instance;
    }

    std::unique_ptr<IShape> createShape() const override
    {
        return std::make_unique<Rectangle>(m_point1, m_point2);
    }

    void setParameters(const sf::Vector2f& point1, const sf::Vector2f& point2)
    {
        m_point1 = point1;
        m_point2 = point2;
    }

private:
    RectangleCreator() = default;
    sf::Vector2f m_point1, m_point2;
};

#endif // LAB2_RECTANGLECREATOR_H
