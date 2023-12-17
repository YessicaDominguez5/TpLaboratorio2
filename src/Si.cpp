#include "Si.h"

Si::Si()
{
    _textureSi.loadFromFile("exit.png");
    _spriteSi.setTexture(_textureSi);
    _spriteSi.setPosition(100,490);
}

void Si::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    target.draw(_spriteSi, states);
}

sf::FloatRect Si::getBounds()const
{
return _spriteSi.getGlobalBounds();
}

sf::Sprite Si::getSpriteBtnSalir(){
    return _spriteSi;
}

