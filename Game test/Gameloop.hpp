#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_set>
#include "Player.hpp"
#include "Room.hpp"
#include <utility>
#include <iostream>

class Gameloop {
public:
    bool running = true;
    std::unordered_set<sf::Keyboard::Key> keys;
    int levels = 5;
    Room level[10][10];  // Assuming you have a Room class to manage tiles
    std::pair<int, int> currentRoom;  // Player's position in the current room
    bool walls[15][20];  // Wall presence in the current room

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
