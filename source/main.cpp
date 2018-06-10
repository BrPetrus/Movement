// Graphics
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

// Utilities
#include <iostream>
#include <chrono>

#include "RectanglePlayer.hpp"

void calculateFPS();

const int WINDOW_HEIGH = 800;
const int WINDOW_WIDTH = 800;

int main()
{

    // Create the window
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGH), "Simple Movement System");
    window.setFramerateLimit(60);

    // Initialize timer

    RectanglePlayer player(sf::Vector2f(50, 50), sf::Vector2f(100, 100), sf::Color::Yellow);

    // Run the program
    while (window.isOpen())
    {
        calculateFPS();

        // Events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
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

/**
 * \brief Calculates and prints out FPS
 * 
 * Keeps track of how many frames passed over a set interval and calculates FPS, which is then printed out using std::cout.
 */
void calculateFPS()
{
    static std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
    static int frames = 1;

    std::chrono::time_point<std::chrono::high_resolution_clock> end = std::chrono::high_resolution_clock::now();
    frames++;

    auto deltaTime = std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(end - start).count();
    if (deltaTime > 1000)
    {
        std::cout << "FPS: " << frames / (deltaTime / 1000) << std::endl;
        start = end;
        frames = 0;
    }
}