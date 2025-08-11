#include "Tile.hpp"

Tile::Tile() : id(0), pos({0, 0}) 
{
    // Default constructor initializes id to 0 and position to (0, 0)
}

Tile::Tile(int ID, int x, int y) : id(ID) , pos({x, y})
{
}

void Tile::update() {
    switch(id)
    {
        default:
            break;
    }
}

void Tile::draw(sf::RenderWindow& window) {
    sf::RectangleShape rectangle(sf::Vector2f(40, 40)); // Assuming tile size is 32x32
    switch (id)
    {
    case 0: //test black tile
        rectangle.setFillColor(sf::Color(0, 0, 0));                 // Fill color
        rectangle.setOutlineThickness(1);                       // Outline thickness
        rectangle.setOutlineColor(sf::Color::Red);                // Outline color
        rectangle.setPosition(pos.first * 40, pos.second*40);                      // Position on screen
        window.draw(rectangle);  // Draw the rectangle
        break;

    case 1: //test red tile
        rectangle.setFillColor(sf::Color(100, 0, 0));                 // Fill color
        rectangle.setOutlineThickness(0);                       // Outline thickness
        rectangle.setPosition(pos.first * 40, pos.second*40);                      // Position on screen
        window.draw(rectangle);  // Draw the rectangle
        break;
    
    case 2: //test wall tile (YES FUNCTIONAL)
        rectangle.setFillColor(sf::Color::Red);                 // Fill color
        rectangle.setOutlineThickness(0);                       // Outline thickness
        rectangle.setPosition(pos.first * 40, pos.second*40);                      // Position on screen
        window.draw(rectangle);  // Draw the rectangle
        break;

    default:
        break;
    }
}