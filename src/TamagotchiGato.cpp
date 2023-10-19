#include "TamagotchiGato.h"

TamagotchiGato::TamagotchiGato():Tamagotchi()
{
    _texture.loadFromFile("TGato.png");
    _sprite.setTexture(_texture);
}


void TamagotchiGato::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    target.draw(_sprite, states);
}

void TamagotchiGato::jugar()
{
    Tamagotchi::jugar();


}
