#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_set>
#include "Player.hpp"

class Gameloop {
public:
    bool running = true;
    std::unordered_set<sf::Keyboard::Key> keys;

    Gameloop();

    void run();
    void processInput();
    void update();
    void render(sf::RenderWindow& window);
    void stop();
private:
    sf::RenderWindow window;
    Player player;  
    sf::View view;
};
