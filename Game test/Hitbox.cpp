#include "Hitbox.hpp"
Hitbox::Hitbox(int x, int y, int X, int Y) : x(x), y(y), X(X), Y(Y) {}

bool Hitbox::overlap(const Hitbox& other) {
    // Check if the rectangles defined by the hitboxes overlap
    return !(X <= other.x || x >= other.X || Y <= other.y || y >= other.Y);
}