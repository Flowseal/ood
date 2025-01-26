#include <fstream>
#include <iostream>
#include <memory>
#include <regex>
#include <sstream>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "Shape/Circle.h"
#include "Shape/Rectangle.h"
#include "Shape/Triangle.h"

std::vector<std::unique_ptr<IShape>> readShapes(std::istream& stream)
{
    std::vector<std::unique_ptr<IShape>> shapes;
    std::string line;

    static const std::regex trianglePattern(R"(TRIANGLE:\s*P1=(\d+),(\d+);\s*P2=(\d+),(\d+);\s*P3=(\d+),(\d+))");
    static const std::regex rectanglePattern(R"(RECTANGLE:\s*P1=(\d+),(\d+);\s*P2=(\d+),(\d+))");
    static const std::regex circlePattern(R"(CIRCLE:\s*C=(\d+),(\d+);\s*R=(\d+))");

    while (std::getline(stream, line))
    {
        std::smatch matches;

        if (std::regex_match(line, matches, trianglePattern))
        {
            shapes.push_back(std::make_unique<Triangle>(
                sf::Vector2f(std::stof(matches[1]), std::stof(matches[2])),
                sf::Vector2f(std::stof(matches[3]), std::stof(matches[4])),
                sf::Vector2f(std::stof(matches[5]), std::stof(matches[6]))));
        }
        else if (std::regex_match(line, matches, rectanglePattern))
        {
            shapes.push_back(std::make_unique<Rectangle>(
                sf::Vector2f(std::stof(matches[1]), std::stof(matches[2])),
                sf::Vector2f(std::stof(matches[3]), std::stof(matches[4]))));
        }
        else if (std::regex_match(line, matches, circlePattern))
        {
            shapes.push_back(std::make_unique<Circle>(
                sf::Vector2f(std::stof(matches[1]), std::stof(matches[2])),
                std::stof(matches[3])));
        }
    }
    return shapes;
}

void writeResults(const std::vector<std::unique_ptr<IShape>>& shapes, std::ostream& stream)
{
    for (const auto& shape : shapes)
    {
        stream << shape->getType() << ": ";
        stream << "P=" << shape->calculatePerimeter() << "; ";
        stream << "S=" << shape->calculateArea() << std::endl;
    }
}

int main()
{
    std::ifstream inputFile("input.txt");
    if (!inputFile.is_open())
    {
        std::cout << "Failed to open input.txt" << std::endl;
        return 1;
    }

    std::ofstream outputFile("output.txt");
    if (!outputFile.is_open())
    {
        std::cout << "Failed to open output.txt" << std::endl;
        return 1;
    }

    auto shapes = readShapes(inputFile);
    writeResults(shapes, outputFile);

    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "Shapes");
    window.clear(sf::Color::White);

    for (const auto& shape : shapes)
    {
        shape->draw(window);
    }

    window.display();

    sf::sleep(sf::seconds(60));

    return 0;
}
