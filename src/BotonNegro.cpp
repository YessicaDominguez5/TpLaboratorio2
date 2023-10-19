#include "BotonNegro.h"

BotonNegro::BotonNegro()
{
    _textureBotonNegro.loadFromFile("botonNegro.png");
    _spriteBotonNegro.setTexture(_textureBotonNegro);
    _spriteBotonNegro.setPosition(375,500);
}

void BotonNegro::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    target.draw(_spriteBotonNegro, states);
}
