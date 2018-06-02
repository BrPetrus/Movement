#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>

#include "RectanglePlayer.hpp"

const int WINDOW_HEIGH = 800;
const int WINDOW_WIDTH = 800;

int main() {

    // Create the window
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGH), "Simple Movement System");
    window.setFramerateLimit(30);

    RectanglePlayer player(sf::Vector2f(50,50), sf::Vector2f(100, 100), sf::Color::Yellow);

    // Run the program
    while(window.isOpen()) {
        // Events
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.close();
            }
        }

        player.update();

        // Background
        window.clear(sf::Color::Green);
        window.draw(player);
        window.display();
    }

    return 0;
}