#include "TamagotchiPerro.h"

TamagotchiPerro::TamagotchiPerro():Tamagotchi()
{
    _texture.loadFromFile("TPerro.png");
    _sprite.setTexture(_texture);

}


void TamagotchiPerro::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    target.draw(_sprite, states);
}

void TamagotchiPerro::jugar()
{
    Tamagotchi::jugar();

}

void TamagotchiPerro::setSpritePerro()
{
    _texture.loadFromFile("TPerro.png");
    _sprite.setTexture(_texture);

}
