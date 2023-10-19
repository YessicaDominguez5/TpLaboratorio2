#include "BotonVerde.h"

BotonVerde::BotonVerde()
{
    _textureBotonVerde.loadFromFile("botonVerde.png");
    _spriteBotonVerde.setTexture(_textureBotonVerde);
    _spriteBotonVerde.setPosition(525,500);
}

void BotonVerde::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    target.draw(_spriteBotonVerde, states);
}
