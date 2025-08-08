#include "Gameloop.hpp"
#include "Player.hpp"

int main() {
    Gameloop gameLoop;
    Player player(gameLoop);
    gameLoop.run();
    return 0;
}
