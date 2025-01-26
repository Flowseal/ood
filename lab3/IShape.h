#ifndef LAB1_ISHAPE_H
#define LAB1_ISHAPE_H

#include <SFML/Graphics.hpp>
class IShapeVisitor;

class IShape
{
public:
    virtual ~IShape() = default;
    virtual std::string getType() const = 0;
    virtual void accept(IShapeVisitor& visitor) const = 0;
    virtual void draw(sf::RenderWindow& window) const = 0;
};

#endif // LAB1_ISHAPE_H
