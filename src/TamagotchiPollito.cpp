#include "TamagotchiPollito.h"

TamagotchiPollito::TamagotchiPollito():Tamagotchi()
{
    _texture.loadFromFile("TPollito.png");
    _sprite.setTexture(_texture);

}


void TamagotchiPollito::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    target.draw(_sprite, states);
}

void TamagotchiPollito::jugar()
{
    Tamagotchi::jugar();


}

void TamagotchiPollito::setSpritePollito()
{
     _texture.loadFromFile("TPollito.png");
    _sprite.setTexture(_texture);
}
