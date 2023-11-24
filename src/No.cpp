#include "No.h"

No::No()
{
    _textureNo.loadFromFile("volver.png");
    _spriteNo.setTexture(_textureNo);
    _spriteNo.setPosition(810,490);
}

void No::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    target.draw(_spriteNo, states);
}

sf::FloatRect No::getBounds()const
{
return _spriteNo.getGlobalBounds();
}

sf::Sprite No::getSpriteBtnSalir(){
    return _spriteNo;
}

