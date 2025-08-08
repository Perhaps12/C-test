#include "Player.hpp"
#include "Gameloop.hpp"
#include <iostream>
using namespace std;

Player::Player(Gameloop& g) : game(g) {
    pos = {400.0, 400.0};  // Initialize player's position
}

void Player::update() {
    move();
}

void Player::move() {
    if (game.keys.count(sf::Keyboard::Left))pos.first -= speed*modifier;  // Move left
    if (game.keys.count(sf::Keyboard::Right))pos.first += speed*modifier;  // Move right
    if (game.keys.count(sf::Keyboard::Up))pos.second -= speed*modifier;  // Move up
    if (game.keys.count(sf::Keyboard::Down))pos.second += speed*modifier;  // Move down
    
    if (game.keys.count(sf::Keyboard::X))modifier = 0.5;
    else modifier = 1.0;
}

void Player::draw(sf::RenderWindow& window) {
    sf::CircleShape circle(10.0f);
    circle.setFillColor(sf::Color::Green);
    circle.setPosition(pos.first, pos.second);
    window.draw(circle);
}
