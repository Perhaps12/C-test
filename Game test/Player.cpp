#include "Player.hpp"
#include "Gameloop.hpp"
#include <iostream>
using namespace std;

vector<pair<int, int>> collisionOrder = {
    {0, 0},
    {0, -1},  // Up
    {0, 1},   // Down
    {-1, 0},  // Left
    {1, 0},    // Right
    {-1, -1}, // Up-Left
    {1, -1},  // Up-Right
    {-1, 1},  // Down-Left
    {1, 1}    // Down-Right
};

Player::Player(Gameloop& g) : game(g) {
    pos = {400.0, 400.0};  // Initialize player's position
    hitbox = {12, 12};  // Initialize player's hitbox radius
    size = {18, 18};  // Initialize player's size radius
}

void Player::update() {
    move();

    for(auto i : collisionOrder){
        if((game.currentRoom.first < 0 || game.currentRoom.first >= 10 || 
            game.currentRoom.second < 0 || game.currentRoom.second >= 10)) break;
        int a = cell.first + i.first;
        int b = cell.second + i.second;
        if(a < 0 || a >= 15 || b < 0 || b >= 20) continue;  // Skip out of bounds
        if(game.walls[a][b]) {
            // Create a hitbox for each wall tile in the current room
            // Assuming each tile is 40x40 pixels
            Hitbox wallHitbox(b * 40, a * 40, (b + 1) * 40, (a + 1) * 40);
            collide(wallHitbox);  // Check for collision with the wall
        }
    }

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
    cell = {(int)(pos.second / 40), (int)(pos.first / 40)};
    
}

void Player::move() {
    if (game.keys.count(sf::Keyboard::Left))pos.first -= speed*modifier;  // Move left
    if (game.keys.count(sf::Keyboard::Right))pos.first += speed*modifier;  // Move right
    if (game.keys.count(sf::Keyboard::Up))pos.second -= speed*modifier;  // Move up
    if (game.keys.count(sf::Keyboard::Down))pos.second += speed*modifier;  // Move down

    if (game.keys.count(sf::Keyboard::X))modifier = 0.6;
    else if (game.keys.count(sf::Keyboard::Z))modifier = 1.5;
    else modifier = 1.0;

}

void Player::collide(Hitbox& wallbox) {
    // Check for collisions with walls in the current room
    Hitbox playerHitbox(pos.first - size.first, pos.second - size.second, 
            pos.first + size.first, pos.second + size.second);
    if (playerHitbox.overlap(wallbox)) {
        // std::cout << "Collision detected with wall at: " 
        //           << wallbox.x << ", " << wallbox.y << " to " 
        //           << wallbox.X << ", " << wallbox.Y << "\n";
        // // Collision detected, adjust position to prevent overlap
        // cout<<pos.first<<" "<<pos.second<<" ("<<wallbox.x<<" "<<wallbox.y<<" "<<wallbox.X<<" "<<wallbox.Y<<") "<<size.first<<"\n";
        double distLeft = pos.first+size.first - wallbox.x; if(distLeft < 0)distLeft = 999999;
        double distRight = wallbox.X - pos.first+size.first; if(distRight < 0)distRight = 999999;
        double distUp = pos.second+size.second - wallbox.y; if(distUp < 0)distUp = 999999;
        double distDown = wallbox.Y - pos.second+size.second; if(distDown < 0)distDown = 999999;
        double minDist = min({distLeft, distRight, distUp, distDown});
        if (minDist == distLeft)pos.first = wallbox.x - size.first-0.3;  // Move left
        if (minDist == distRight)pos.first = wallbox.X + size.first+0.3;  // Move right
        if (minDist == distUp)pos.second = wallbox.y - size.second-0.3;  // Move up
        if (minDist == distDown)pos.second = wallbox.Y + size.second+0.3;  // Move down 
    }
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
