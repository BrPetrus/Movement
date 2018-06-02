#include "RectanglePlayer.hpp"

RectanglePlayer::RectanglePlayer(sf::Vector2f position, sf::Vector2f size, sf::Color color) :
_velocityX(10, 0), _velocityY(0, 10) {
    _shape.setSize(size);
    _shape.setPosition(position);
    _shape.setFillColor(color);
}

void RectanglePlayer::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_shape, states);
}

void RectanglePlayer::update() {
    // Check global keyboard input
    sf::Vector2f newPosition = _shape.getPosition();

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        //_shape.move(sf::Vector2f(-10,0));
        newPosition -= _velocityX;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        //_shape.move(sf::Vector2f(10,0));
        newPosition +=_velocityX;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        //_shape.move(sf::Vector2f(0,-10));
        newPosition -= _velocityY;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
       // _shape.move(sf::Vector2f(0,10));
        newPosition +=_velocityY;
    }

    _shape.setPosition(newPosition);
}