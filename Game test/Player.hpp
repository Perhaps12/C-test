#pragma once
#include <SFML/Graphics.hpp>
#include <utility>
#include "Hitbox.hpp"

class Gameloop;  // Forward declare Gameloop to avoid circular include

class Player {
public:
    Player(Gameloop& game);
    void update();
    void move();
    void collide(Hitbox& wallbox);
    void draw(sf::RenderWindow& window);

    std::pair<double, double> pos;  // Player's position in the game
    std::pair<int, int> hitbox;  // Player's hitbox radius
    std::pair<int, int> size;  // Player's size
    std::pair<int, int> cell;
    double speed = 5.2, modifier = 1.0;  // Movement speed and modifier
private:
    Gameloop& game;  // Reference to Gameloop for interaction
};
