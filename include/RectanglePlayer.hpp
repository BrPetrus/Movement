#ifndef RECTANGLEPLAYER_HPP
#define RECTANGLEPLAYER_HPP

#include <SFML/Graphics.hpp>

class RectanglePlayer : public sf::Drawable{
public:
    RectanglePlayer(sf::Vector2f, sf::Vector2f size, sf::Color);
    //virtual ~RectanglePlayer() {};

    void update();
    
private:
    sf::RectangleShape _shape;
    sf::Vector2f _velocityX;
    sf::Vector2f _velocityY;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif