#pragma once
#include <SFML/Graphics.hpp>
#include <utility>

class Hitbox{
public:
    int x, y, X, Y; //bounds of the hitbox
    Hitbox(int x, int y, int X, int Y);
    bool overlap(const Hitbox& other);
};