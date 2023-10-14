#include "Salud.h"


Salud::Salud()
{

}

void Salud::SetearImagen(){
     _textureSalud.loadFromFile("CorazonSalud.png");
    _spriteSalud.setTexture(_textureSalud);
   //sprite agarrado desde el centro
    _spriteSalud.setOrigin(_spriteSalud.getGlobalBounds().width/2, _spriteSalud.getGlobalBounds().height/2);
}


void Salud::setearPosicion(int x)
{
    int y = 25;

        _spriteSalud.setPosition(x,y);

}

void Salud::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    target.draw(_spriteSalud, states);
}

sf::Sprite Salud::getSprite(){
    return _spriteSalud;
}


