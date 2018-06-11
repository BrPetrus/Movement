#include "RectanglePlayer.hpp"

#include <iostream>

// Default constructor
RectanglePlayer::RectanglePlayer(sf::Vector2f pos, sf::Vector2f vel, sf::Vector2f acc, sf::Vector2f size, sf::Color colour, float mass) :
_mass(mass), _position(pos), _velocity(vel), _acceleration(acc) {
    _shape.setSize(size);
    _shape.setPosition(_position);
    _shape.setFillColor(colour); 
}

void RectanglePlayer::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_shape, states);
}

void RectanglePlayer::update(double deltaTime, float thrust) {
    // v = u + at
    // s = ut + at*t/2
    // f = ma

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        _acceleration.x = _acceleration.x - (thrust/_mass);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        _acceleration.x = _acceleration.x + (thrust/_mass);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
       _acceleration.y = _acceleration.y - (thrust/_mass);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        _acceleration.y = _acceleration.y + (thrust/_mass);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
        std::cout << "(" << _position.x << "," << _position.y << ")" << std::endl;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
        std::cout << "Reseted vel. and acc. vector" << std::endl;
        _velocity = sf::Vector2f(0,0);
        _acceleration = sf::Vector2f(0,0);
    }

    float posX = _position.x + _velocity.x*deltaTime + 0.5*deltaTime*deltaTime*_acceleration.x;
    float posY = _position.y + _velocity.y*deltaTime + 0.5*deltaTime*deltaTime*_acceleration.y;
    _position = sf::Vector2f(posX, posY);
    _shape.setPosition(_position);

    // Reset all forces
    //_acceleration = sf::Vector2f(0,0);
}