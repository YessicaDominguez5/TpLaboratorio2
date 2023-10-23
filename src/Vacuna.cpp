#include "Vacuna.h"

Vacuna::Vacuna()
{
   _textureVacuna.loadFromFile("vacuna.png");
    _spriteVacuna.setTexture(_textureVacuna);
    _spriteVacuna.setOrigin(_spriteVacuna.getGlobalBounds().width/2, _spriteVacuna.getGlobalBounds().height/2);
    _spriteVacuna.setPosition(350,350);
}
Vacuna::~Vacuna(){}

void Vacuna::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    target.draw(_spriteVacuna, states);
}

sf::FloatRect Vacuna::getBounds()const
{
    return _spriteVacuna.getGlobalBounds();
}


void Vacuna::respawn()
{


     _spriteVacuna.setPosition(std::rand()%700 + _spriteVacuna.getGlobalBounds().width, std::rand()%500 + _spriteVacuna.getGlobalBounds().height);
}
