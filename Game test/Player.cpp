#include "Player.hpp"
#include "Gameloop.hpp"
#include <iostream>
using namespace std;

Player::Player(Gameloop& g) : game(g) {
    pos = {400.0, 400.0};  // Initialize player's position
    hitbox = {12, 12};  // Initialize player's hitbox radius
    size = {18, 18};  // Initialize player's size radius
}

void Player::update() {
    move();
    if(pos.first < 0){
        game.currentRoom.first -= 1;  // Move to the left room
        pos.first+= 800;  // Wrap around the screen horizontally
    }
    if(pos.first > 800){
        game.currentRoom.first += 1;  // Move to the right room
        pos.first-= 800;  // Wrap around the screen horizontally
    }
    if(pos.second < 0){
        game.currentRoom.second -= 1;  // Move to the upper room
        pos.second+= 600;  // Wrap around the screen vertically
    }
    if(pos.second > 600){
        game.currentRoom.second += 1;  // Move to the lower room
        pos.second-= 600;  // Wrap around the screen vertically
    }
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

    //size demo
    sf::CircleShape circle(size.first);
    circle.setFillColor(sf::Color(0, 180, 0));
    circle.setPosition(pos.first-size.first, pos.second-size.second);
    window.draw(circle);
    //hitbox demo
    sf::CircleShape cirque(hitbox.first);
    cirque.setFillColor(sf::Color(0, 255, 0));
    cirque.setPosition(pos.first-hitbox.first, pos.second-hitbox.second);
    window.draw(cirque);

    // //test
    // sf::RectangleShape rectangle(sf::Vector2f(40, 40)); // width=200, height=100
    // rectangle.setFillColor(sf::Color(0, 0, 0, 0));                 // Fill color
    // rectangle.setOutlineThickness(1);                       // Outline thickness
    // rectangle.setOutlineColor(sf::Color::Red);                // Outline color
    // rectangle.setPosition(pos.first - 20, pos.second-20);                      // Position on screen
    // window.draw(rectangle);  // Draw the rectangle

}
