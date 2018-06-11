// Graphics
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

// Utilities
#include <iostream>
#include <chrono>

#include "RectanglePlayer.hpp"

double calculateFPS(double deltaTime);
void calculateAndPrintFPS();

const int WINDOW_HEIGH = 800;
const int WINDOW_WIDTH = 800;

int main()
{

    // Create the window
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGH), "Simple Movement System");
    window.setFramerateLimit(60);

    
    RectanglePlayer player(sf::Vector2f(50, 50), sf::Vector2f(100, 100), sf::Color::Yellow);
    
    // Initialize timer
    std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();


    // Run the program
    while (window.isOpen())
    {
        std::chrono::time_point<std::chrono::high_resolution_clock> end = std::chrono::high_resolution_clock::now();
        auto deltaTime = std::chrono::duration_cast<std::chrono::duration<double, std::milli>>(end - start).count();
        //std::cout << calculateFPS(deltaTime) << std::endl;

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

        start=end;
    }
    return 0;
}

/**
 * \brief Calculates FPS.
 * 
 * Calculates FPS from deltaTime and returns it.
 */
double calculateFPS(double deltaTime)
{
    return (1/(deltaTime/1000));
}

/**
 * \brief Calculates and prints out FPS
 * 
 * Keeps track of how many frames passed over a set interval and calculates FPS, which is then printed out using std::cout.
 */
void calculateAndPrintFPS()
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