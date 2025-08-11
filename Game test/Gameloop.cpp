#include "Gameloop.hpp"

// Forward declaration (required before calling it in Gameloop::run)
sf::View getLetterboxView(sf::View view, int windowWidth, int windowHeight);

Gameloop::Gameloop()
    : window(sf::VideoMode(800, 600), "SFML Window"),
      player(*this),
      view(sf::FloatRect(0.f, 0.f, 800.f, 600.f))
{
    window.setView(view); 
    for(int i = 0 ; i < 10; i++){
        for(int j = 0; j < 10; j++){
            level[i][j] = Room();  // Initialize each room with default tiles
        }
    }
}

void Gameloop::run() {
    window.setFramerateLimit(30);

    while (running) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed){
                window.close();
                running = false;
            }

            if(event.type == sf::Event::KeyPressed) {
                keys.insert(event.key.code);
            }

            if (event.type == sf::Event::KeyReleased) {
                keys.erase(event.key.code);
            }

            if (event.type == sf::Event::Resized) {
                // Apply letterboxing on resize
                view = getLetterboxView(view, event.size.width, event.size.height);
                window.setView(view);
            }
        }

        window.clear(sf::Color(0, 0, 0)); 

        // processInput();
        update();
        render(window);

        window.display();
    }
}

void Gameloop::processInput() {
    // You can pass keys to player or handle movement here
}

void Gameloop::update() {
    // std::cout<<currentRoom.first<<" "<<currentRoom.second<<"\n";
    for(int i = 0; i < 15; i++) {
        for(int j = 0; j < 20; j++) {
            walls[i][j] = (level[currentRoom.first][currentRoom.second].tiles[i][j].id == 2);
            //maybe use .count & set to define walls (?)
        }
    }
    player.update();  // Update player state
}

void Gameloop::render(sf::RenderWindow& window) {
    if(!(currentRoom.first < 0 || currentRoom.first >= 10 || 
       currentRoom.second < 0 || currentRoom.second >= 10)) {
        level[currentRoom.first][currentRoom.second].draw(window);  // Draw the current room
    }
    player.draw(window); 

}

void Gameloop::stop() {
    running = false;
}

// Function to apply letterboxing to the view
sf::View getLetterboxView(sf::View view, int windowWidth, int windowHeight)
{
    float windowRatio = static_cast<float>(windowWidth) / static_cast<float>(windowHeight);
    float viewRatio = view.getSize().x / view.getSize().y;
    float sizeX = 1.f;
    float sizeY = 1.f;
    float posX = 0.f;
    float posY = 0.f;

    if (windowRatio < viewRatio) {
        sizeY = windowRatio / viewRatio;
        posY = (1.f - sizeY) / 2.f;
    } else {
        sizeX = viewRatio / windowRatio;
        posX = (1.f - sizeX) / 2.f;
    }

    view.setViewport(sf::FloatRect(posX, posY, sizeX, sizeY));
    return view;
}