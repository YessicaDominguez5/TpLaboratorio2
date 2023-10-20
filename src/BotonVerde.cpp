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

sf::FloatRect BotonVerde::getBounds()const
{
return _spriteBotonVerde.getGlobalBounds();
}

sf::Sprite BotonVerde::getSpriteBtnVerde(){
    return _spriteBotonVerde;
}
