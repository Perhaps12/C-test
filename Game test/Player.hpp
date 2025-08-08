#pragma once
#include <SFML/Graphics.hpp>
#include <utility>

class Gameloop;  // Forward declare Gameloop to avoid circular include

class Player {
public:
    Player(Gameloop& game);
    void update();
    void move();
    void draw(sf::RenderWindow& window);

    std::pair<double, double> pos;  // Player's position in the game
    double speed = 5.0, modifier = 1.0;  // Movement speed and modifier
private:
    Gameloop& game;  // Reference to Gameloop for interaction
};
