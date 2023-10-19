#include "BotonRojo.h"

BotonRojo::BotonRojo()
{
    _textureBotonRojo.loadFromFile("botonRojo.png");
    _spriteBotonRojo.setTexture(_textureBotonRojo);
    _spriteBotonRojo.setPosition(40,500);
}

void BotonRojo::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    target.draw(_spriteBotonRojo, states);
}

sf::FloatRect BotonRojo::getBounds()const
{
return _spriteBotonRojo.getGlobalBounds();
}
