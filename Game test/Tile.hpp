#pragma once
#include <SFML/Graphics.hpp>
#include <utility>

class Tile{
public:
    int id;
    std::pair<int, int> pos;  // Position of the tile in the game world
    Tile();
    Tile(int ID, int x, int y);
    void update();
    void draw(sf::RenderWindow& window);
    

};