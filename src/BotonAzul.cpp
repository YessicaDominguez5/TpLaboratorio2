#include "BotonAzul.h"

BotonAzul::BotonAzul()
{
    _textureBotonAzul.loadFromFile("botonAzul.png");
    _spriteBotonAzul.setTexture(_textureBotonAzul);
    _spriteBotonAzul.setPosition(220,500);
}

void BotonAzul::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    target.draw(_spriteBotonAzul, states);
}
