#pragma once
#include <SFML/Graphics.hpp>
#include "Tile.hpp"

class Room{
public:
    Tile tiles[15][20];
    Room();
    Room(int arr[15][20]);
    void update();
    void draw(sf::RenderWindow& window);
};