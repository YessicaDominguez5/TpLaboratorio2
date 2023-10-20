#include "Pizza.h"

Pizza::Pizza()
{
   _texturePizza.loadFromFile("pizza.png");
    _spritePizza.setTexture(_texturePizza);
    _spritePizza.setOrigin(_spritePizza.getGlobalBounds().width/2, _spritePizza.getGlobalBounds().height/2);
}

void Pizza::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    target.draw(_spritePizza, states);
}

sf::FloatRect Pizza::getBounds()const
{
    return _spritePizza.getGlobalBounds();
}


void Pizza::respawn()
{
     std::srand((unsigned)std::time(0));

     _spritePizza.setPosition(std::rand()%500 + _spritePizza.getGlobalBounds().width, std::rand()%500 + _spritePizza.getGlobalBounds().height);
}