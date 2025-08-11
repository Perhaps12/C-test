#include "Room.hpp"

Room::Room() {
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 20; j++) {
            tiles[i][j] = Tile((i+j)%2, j, i);  // Default tile ID is 0
        }
    }
}

Room::Room(int arr[15][20]) {
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 20; j++) {
            tiles[i][j] = Tile(arr[i][j], j, i);  // Default tile ID is 0
        }
    }
}

// void::update(){

// }

void Room::draw(sf::RenderWindow& window) {
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 20; j++) {
            tiles[i][j].draw(window);  // Draw each tile
        }
    }
}