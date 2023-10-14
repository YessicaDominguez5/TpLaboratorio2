#include "Entretenimiento.h"

Entretenimiento::Entretenimiento()
{
    _spriteEntretenimiento.setPosition(250,60);
}
void Entretenimiento::TipoEntretenimiento(bool entretenimiento)
{
    if(entretenimiento == true)
    {
        _textureEntretenimiento.loadFromFile("divertido.png");
        _spriteEntretenimiento.setTexture(_textureEntretenimiento);

    }
    else
    {

        _textureEntretenimiento.loadFromFile("aburrido.png");
        _spriteEntretenimiento.setTexture(_textureEntretenimiento);



    }

}

void Entretenimiento::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    target.draw(_spriteEntretenimiento, states);
}
