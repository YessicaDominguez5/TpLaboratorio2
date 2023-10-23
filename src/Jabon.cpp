#include "Jabon.h"

Jabon::Jabon()
{
   _textureJabon.loadFromFile("jabon.png");
    _spriteJabon.setTexture(_textureJabon);
    _spriteJabon.setOrigin(_spriteJabon.getGlobalBounds().width/2, _spriteJabon.getGlobalBounds().height/2);
    _spriteJabon.setPosition(350,350);
}

Jabon::~Jabon(){}

void Jabon::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    target.draw(_spriteJabon, states);
}

sf::FloatRect Jabon::getBounds()const
{
    return _spriteJabon.getGlobalBounds();
}


void Jabon::respawn()
{


     _spriteJabon.setPosition(std::rand()%700 + _spriteJabon.getGlobalBounds().width, std::rand()%500 + _spriteJabon.getGlobalBounds().height);
}
