#include "Room.hpp"

Room::Room() {
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 20; j++) {
            tiles[i][j] = Tile((i+j)%2, j, i);  // Default tile ID is 0
            if(i%5 == 0 && j%3 == 0)tiles[i][j].id = 2;
            if((i==0||j==0||i==14||j==19)&&i!=4&&i!=3&&j!=8&&j!=7)tiles[i][j].id = 2;
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

void Room::update(){
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 20; j++) {
            tiles[i][j].update();  // Update each tile
        }
    }
}

void Room::draw(sf::RenderWindow& window) {
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 20; j++) {
            tiles[i][j].draw(window);  // Draw each tile
        }
    }
}