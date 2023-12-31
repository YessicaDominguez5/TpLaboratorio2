#include "BotonGris.h"

BotonGris::BotonGris()
{
    _textureBotonGris.loadFromFile("botonGris.png");
    _spriteBotonGris.setTexture(_textureBotonGris);
    _spriteBotonGris.setPosition(700,500);
}

void BotonGris::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    target.draw(_spriteBotonGris, states);
}

sf::FloatRect BotonGris::getBounds()const
{
    return _spriteBotonGris.getGlobalBounds();
}

sf::Sprite BotonGris::getSpriteBtnGris(){
    return _spriteBotonGris;
}
