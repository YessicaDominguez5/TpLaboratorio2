#include "Manzana.h"

Manzana::Manzana()
{
    _textureManzana.loadFromFile("manzana.png");
    _spriteManzana.setTexture(_textureManzana);
    _spriteManzana.setOrigin(_spriteManzana.getGlobalBounds().width/2, _spriteManzana.getGlobalBounds().height/2);
}

Manzana::~Manzana()
{
    //dtor
}

void Manzana::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    target.draw(_spriteManzana, states);
}

sf::FloatRect Manzana::getBounds()const
{
    return _spriteManzana.getGlobalBounds();
}


void Manzana::respawn()
{

     _spriteManzana.setPosition(std::rand()%700 + _spriteManzana.getGlobalBounds().width, std::rand()%500 + _spriteManzana.getGlobalBounds().height);
}
