#ifndef RECTANGLEPLAYER_HPP
#define RECTANGLEPLAYER_HPP

#include <SFML/Graphics.hpp>

class RectanglePlayer : public sf::Drawable{
public:
    //virtual ~RectanglePlayer() {};
    RectanglePlayer(sf::Vector2f pos, sf::Vector2f vel, sf::Vector2f acc, sf::Vector2f size, sf::Color colour, float mass);

    void update(double deltaTime, float thrust);
    
private:
    float _mass;
    sf::Vector2f _position;
    sf::Vector2f _velocity;
    sf::Vector2f _acceleration;
    
    sf::RectangleShape _shape;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif